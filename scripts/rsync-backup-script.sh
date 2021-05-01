#!/bin/bash

rsync -aP --exclude-from=exclusions /home/kgbeast/ /home/kgbeast/.backups/weekly
