#!/bin/bash
rm app lib/libbar.so
gcc lib/bar.c -fpic -shared -o lib/libbar.so
gcc app.c -Ilib -Llib -lbar -rdynamic -o app
LD_LIBRARY_PATH=lib LD_DEBUG=symbols ./app
