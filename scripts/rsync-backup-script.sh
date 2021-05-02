#!/bin/bash

rsync -r --exclude-from=exclusions /home/kgbeast/ /home/kgbeast/.backups/weekly
