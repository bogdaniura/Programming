#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Function to print status
print_status() {
    if [ $1 -eq 0 ]; then
        echo -e "${GREEN}✓ $2${NC}"
    else
        echo -e "${RED}✗ $2${NC}"
        exit 1
    fi
}

# Create test files
echo "Creating test files..."
cd "$(dirname "$0")"
rm -rf source/* docs/* images/* archives/* code/* 2>/dev/null

# Create some test files
echo "test content" > source/document1.pdf
echo "test content" > source/document2.txt
echo "test content" > source/image1.jpg
echo "test content" > source/image2.png
echo "test content" > source/archive1.zip
echo "test content" > source/archive2.tar.gz
echo "test content" > source/script1.py
echo "test content" > source/script2.sh

print_status $? "Created test files"

# Run the sorting script
echo "Running sorting script..."
python3 sort_files.py
print_status $? "Ran sorting script"

# Verify results
echo "Verifying results..."

# Check if files were moved to correct directories
[ -f "docs/document1.pdf" ] && [ -f "docs/document2.txt" ]
print_status $? "Documents sorted correctly"

[ -f "images/image1.jpg" ] && [ -f "images/image2.png" ]
print_status $? "Images sorted correctly"

[ -f "archives/archive1.zip" ] && [ -f "archives/archive2.tar.gz" ]
print_status $? "Archives sorted correctly"

[ -f "code/script1.py" ] && [ -f "code/script2.sh" ]
print_status $? "Code files sorted correctly"

# Check if source directory is empty
[ -z "$(ls -A source)" ]
print_status $? "Source directory is empty"

echo "All tests passed successfully!" 