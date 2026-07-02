#!/bin/sh
# Toggle Thunderbird visibility using Birdtray's command line interface
# This script assumes "birdtray" is in the PATH or installed to /usr/local/bin
exec birdtray -t "$@"
