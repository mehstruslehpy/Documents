#!/bin/bash
# stolen from SO useful for sorting tld's
# sorts $1 by length
awk '{ print length, $0 }' $1 | sort -n -r | cut -d' ' -f2-
