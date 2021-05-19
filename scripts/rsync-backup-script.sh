#!/bin/bash

konsole -e "rsync -a --exclude-from=exclusions /home/kgbeast/ /home/kgbeast/.backups/weekly"
