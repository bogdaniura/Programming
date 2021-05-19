#!/bin/bash

#this is a test script

konsole -e "rsync -rv --exclude-from=exclusions /home/kgbeast/ /home/kgbeast/.backups/weekly"