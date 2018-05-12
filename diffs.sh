#!/usr/bin/env bash

# This test verifies that the code compiles cleanly with -Wall.
# The default timeout for tests is 2 seconds; we increase it here
# because compilation can take a while.

#@test{"stderr":10, "stdout": 10, "timeout": 10}
make -B -f check_make_errors

#@test{"stdout":80}
./makeBox `../extractEmail.py submission_metadata.json`

