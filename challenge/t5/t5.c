#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include <linux/usb/input.h>
#include <linux/hid.h>

MODULE_LICENSE("GPL");

static struct usb_device_id usb_t5_id_table[] = {
    { USB_INTERFACE_INFO(
        USB_INTERFACE_CLASS_HID,
        USB_INTERFACE_SUBCLASS_BOOT,
    USB_INTERFACE_PROTOCOL_KEYBOARD) },
    { } /* Terminating entry */
};

MODULE_DEVICE_TABLE(usb, usb_t5_id_table);

static int t5_probe(struct usb_interface *interface,
    const struct usb_device_id *id)
{
    pr_info("USB keyboard probe function called\n");
    return 0;
}

static void t5_disconnect(struct usb_interface *interface)
{
    pr_info("USB keyboard disconnect function called\n");
}

static struct usb_driver t5_driver = {
    .name  = "usbt5",
    .probe = t5_probe,
    .disconnect = t5_disconnect,
    .id_table = usb_t5_id_table,
};

static int __init t5_init(void)
{
    int res = 0;
    res = usb_register(&t5_driver);
    if (res)
        pr_err("usb_register failed with error %d", res);
    return res;
}

static void __exit t5_exit(void)
{
    pr_debug("USB Keyboard Removed..\n");
    usb_deregister(&t5_driver);
    return;
}

module_init(t5_init);
module_exit(t5_exit);