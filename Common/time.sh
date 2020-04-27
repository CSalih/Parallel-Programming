#!/bin/bash

# Author: bobmcn (https://stackoverflow.com/a/33422179)
# usage ./time.sh Executable [args]

rm -f /tmp/mtime.$$

if [ -z $1 ]
then
    echo "Usage: ./time.sh ./executable [args]"
    exit 1
fi

if [ ! -f "$1" ]
then
    echo "File not exits! $1"
    exit 1
fi

echo "Real, User, System"
for x in {1..10}
do
  /usr/bin/time -f "%e, %U, %S" -a -o /tmp/mtime.$$ $@ > /dev/null 2>&1
  tail -1 /tmp/mtime.$$
done

awk '{ et += $1; ut += $2; st += $3; count++ } END {  printf "Average:\n%.3f, %.3f, %.3f\n", et/count, ut/count, st/count }' /tmp/mtime.$$