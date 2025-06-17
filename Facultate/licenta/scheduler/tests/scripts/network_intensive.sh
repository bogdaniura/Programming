#!/bin/bash

echo "Starting network intensive task at $(date)"
# Create a Python script for network operations
cat > /tmp/network_test.py << 'EOF'
import requests
import concurrent.futures
import time

def fetch_url(url):
    try:
        response = requests.get(url, timeout=10)
        return f"Status: {response.status_code}, Size: {len(response.content)} bytes"
    except Exception as e:
        return f"Error: {str(e)}"

# List of URLs to test
urls = [
    "https://www.google.com",
    "https://www.github.com",
    "https://www.python.org",
    "https://www.stackoverflow.com",
    "https://www.reddit.com"
]

# Perform concurrent requests
print("Starting concurrent requests...")
with concurrent.futures.ThreadPoolExecutor(max_workers=5) as executor:
    results = list(executor.map(fetch_url, urls))

# Print results
for url, result in zip(urls, results):
    print(f"{url}: {result}")

EOF

# Run the Python script
python3 /tmp/network_test.py
echo "Finished network intensive task at $(date)" 