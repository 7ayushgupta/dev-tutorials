#!/bin/bash

touch myfile

while [ ! -e myfile ]; do
sleep 1
done

file="./myfile"
if [ -w $file ]; then
    echo "File is writable"
else
    echo "File is not writable"
fi

rm -rf $file