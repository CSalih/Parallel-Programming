#!/bin/bash

# Author: bobmcn (https://stackoverflow.com/a/33422179)
# usage ./time.sh Executable [args]

rm -f /tmp/mtime.$$

if [ -z $1 ]
then
    echo "Usage: ./time.sh executable [args]"
    exit 1
fi

if [ ! -f "$1" ]
then
    echo "File not exits! $1"
    exit 1
fi

for x in {1..10}
do
  /usr/bin/time -f "real %e user %U sys %S" -a -o /tmp/mtime.$$ $@ > /dev/null 2>&1
  tail -1 /tmp/mtime.$$
done

awk '{ et += $2; ut += $4; st += $6; count++ } END {  printf "Average:\nreal %.3f user %.3f sys %.3f\n", et/count, ut/count, st/count }' /tmp/mtime.$$