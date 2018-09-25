# !/bin/bash
curl --silent 'http://aqicn.org/?city=Shanghai&widgetscript&size=large&id=52b39d71decf07.20261781' | sed -e "s/<[^>]*>//g" -e "s/.*Air Quality.\([0-9]*\).*Temp. \([0-9]*\).*/AQ: \1 Temp: \2°C/g" -e "s/^[^A].*//g"
