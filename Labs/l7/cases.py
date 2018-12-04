import os
import random
import shutil
import subprocess
import time
import string

random.seed(482)

print('compiling')
if os.path.exists('solution'):
    shutil.rmtree('solution')
shutil.copytree('../origin', 'solution')
os.chdir('solution')
# result = subprocess.run(['make'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
# print(result.stdout.decode())
# print(result.stderr.decode())
result = subprocess.run(['clang', '-o', 'main', '../driver/main.c', 'dlist.c', '-I', '.'], stdout=subprocess.PIPE,
                        stderr=subprocess.PIPE)
print(result.stderr.decode())
os.chdir('..')

if os.path.exists('solution2'):
    shutil.rmtree('solution2')
shutil.copytree('../c++', 'solution2')
os.chdir('solution2')
result = subprocess.run(['clang++', '-o', 'main', 'main.cpp', 'dlist.cpp'], stdout=subprocess.PIPE,
                        stderr=subprocess.PIPE)
print(result.stderr.decode())
os.chdir('..')


def generate_random_str(n):
    return ''.join(random.sample(string.ascii_letters + string.digits, n))


data_type_names = ['int', 'str', 'double']
data_type_num = len(data_type_names)
sort_type_names = ['inc', 'dec']
sort_type_num = len(sort_type_names)

sizes = [5, 10, 50, 100, 1000]

config_file = open('../config.yaml', 'r')
config_str = config_file.read()
config_file.close()
config_file = open('config.yaml', 'w')
config_file.write(config_str)

count = 0

for size in sizes:
    for data_type in data_type_names:
        count += 1
        input_name = 'case%d.in' % count
        output_name = 'case%d.out' % count

        stdin = '%d %s\n' % (size, data_type)
        for i in range(size - 1):
            r = random.random()
            if r < 0.8:  # append
                s = generate_random_str(random.randint(5, 15))
                if data_type == 'int':
                    v = str(random.randint(-1024, 1024))
                elif data_type == 'str':
                    v = generate_random_str(random.randint(3, 5))
                else:
                    v = str(random.random())
                stdin += 'append %s %s\n' % (s, v)
            elif r < 0.9:
                if r < 0.85:
                    stdin += 'sort %s\n' % sort_type_names[0]
                else:
                    stdin += 'sort %s\n' % sort_type_names[1]
            elif r < 0.95:
                stdin += 'empty\n'
            else:
                stdin += 'print\n'
        stdin += 'print\n'
        stdin = bytes(stdin, encoding='utf-8')

        with open(input_name, 'wb') as file:
            file.write(stdin)

        result = subprocess.run(['solution/main'], input=stdin, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        result2 = subprocess.run(['solution2/main'], input=stdin, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

        with open(output_name, 'wb') as file:
            file.write(result.stdout)
        # with open(output_name + '.2', 'wb') as file:
        #     file.write(result2.stdout)

        config_file.write('- <<: *default\n')
        config_file.write('  input: %s\n' % input_name)
        config_file.write('  output: %s\n' % output_name)

# for iteration, (grid_m, grid_n) in enumerate(grid_sizes):
#     print('generating size %d x %d' % (grid_m, grid_n))
#     size = grid_m * grid_n
#     max_range = 2 ** 31 // size
#     # max_range = min(2 ** 31 // size, 512)
#     nums = generate_random_list(size, max_range)
#
#     input_name = 'size_%d_%d.in' % (grid_m, grid_n)
#
#     stdin = ''
#     for i in range(grid_n):
#         for j in range(grid_m):
#             stdin += str(nums[i * grid_m + j]) + ' '
#         stdin += '\n'
#     stdin = bytes(stdin, encoding='utf-8')
#
#     with open(input_name, 'wb') as file:
#         file.write(stdin)
#
#     start_end_pos_set = set()
#
#     for repeat in range(sizes[iteration]):
#         output_names = ['size_%d_%d_%d.out' % (grid_m, grid_n, repeat),
#                         'size_%d_%d_%d_v.out' % (grid_m, grid_n, repeat)]
#         first = [True, True]
#
#         while True:
#             start_pos = [str(random.randint(0, grid_m - 1)), str(random.randint(0, grid_n - 1))]
#             while True:
#                 end_pos = [str(random.randint(0, grid_m - 1)), str(random.randint(0, grid_n - 1))]
#                 if start_pos != end_pos:
#                     break
#             start_end_pos = ' '.join(start_pos + end_pos)
#             if start_end_pos not in start_end_pos_set:
#                 start_end_pos_set.add(start_end_pos)
#                 break
#
#         for i in range(algorithm_num):
#             if size > algorithm_max_size[i]:
#                 continue
#
#             argv = ['./main', '-i', algorithm_names[i]]
#
#             for j in range(verbose_num):
#                 if j > 0 and size > verbose_max_size:
#                     continue
#                 count += 1
#                 case_name = 'case%02d' % count
#                 _argv = [*argv]
#                 if len(verbose_names[j]) > 0:
#                     _argv.append(verbose_names[j])
#                 _argv = ['./driver', str(len(_argv)), *_argv,
#                          str(grid_m), str(grid_n),
#                          str(start_pos[0]), str(start_pos[1]),
#                          str(end_pos[0]), str(end_pos[1])]
#                 os.chdir('solution')
#                 start = time.time()
#                 result = subprocess.run(_argv, input=stdin, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
#                 end = time.time()
#                 os.chdir('..')
#                 print(result.returncode, _argv[1:])
#                 if result.returncode != 0:
#                     print(result.returncode, _argv)
#                 if first:
#                     with open(output_names[j], 'wb') as file:
#                         file.write(result.stdout)
#                 time_limit = str(int(((end - start) * 2 + 0.2) * 10) / 10.0)
#                 config_file.write('- <<: *default\n')
#                 config_file.write('  input: %s\n' % input_name)
#                 config_file.write('  output: %s\n' % output_names[j])
#                 config_file.write('  time: %ss\n' % time_limit)
#                 config_file.write('  execute_args: \"%s\" \n' % ' '.join(_argv[1:]))
#                 config_file.write('  category: %s\n' % 'sentence')
#                 if size > memory_extend_size:
#                     config_file.write('  memory: 256m\n')
#                 print('%s generated in %f s, time limit %s s' % (case_name, end - start, time_limit))
#
#     # break

config_file.close()
shutil.rmtree('solution')
shutil.rmtree('solution2')
print('finished')
