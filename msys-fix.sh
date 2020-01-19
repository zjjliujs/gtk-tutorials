#!/bin/bash

fix_file="CMakeFiles/gtk-test.dir/flags.make"

if [ ! -f "${fix_file}" ]
then
	echo "${fix_file} not found!"
fi
sed -iv 's/\/home\/liujinsong\/gtk-tutorials\/app1\/D:\/msys64//g' CMakeFiles/gtk-test.dir/flags.make
