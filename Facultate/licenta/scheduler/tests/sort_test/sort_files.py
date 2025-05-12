#!/usr/bin/env python3
import os
import shutil
import logging
from pathlib import Path

# Configure logging
logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(levelname)s - %(message)s'
)

# Define file type mappings
FILE_TYPES = {
    'docs': ['.pdf', '.txt', '.doc', '.docx', '.md'],
    'images': ['.jpg', '.jpeg', '.png', '.gif', '.bmp'],
    'archives': ['.zip', '.tar.gz', '.rar', '.7z'],
    'code': ['.py', '.sh', '.js', '.html', '.css']
}

def sort_files(source_dir: str):
    """Sort files from source directory into appropriate subfolders based on their extensions."""
    source_path = Path(source_dir)
    
    # Ensure source directory exists
    if not source_path.exists():
        logging.error(f"Source directory {source_dir} does not exist")
        return False
        
    # Process each file in the source directory
    for file_path in source_path.iterdir():
        if file_path.is_file():
            # Get file extension
            ext = file_path.suffix.lower()
            
            # Determine target directory
            target_dir = None
            for dir_name, extensions in FILE_TYPES.items():
                if ext in extensions:
                    target_dir = source_path.parent / dir_name
                    break
                    
            if target_dir:
                # Create target directory if it doesn't exist
                target_dir.mkdir(exist_ok=True)
                
                # Move file to target directory
                try:
                    shutil.move(str(file_path), str(target_dir / file_path.name))
                    logging.info(f"Moved {file_path.name} to {target_dir.name}")
                except Exception as e:
                    logging.error(f"Error moving {file_path.name}: {e}")
            else:
                logging.warning(f"No target directory found for {file_path.name}")
                
    return True

if __name__ == "__main__":
    # Get the directory where this script is located
    script_dir = Path(__file__).parent
    source_dir = script_dir / "source"
    
    if sort_files(str(source_dir)):
        logging.info("File sorting completed successfully")
    else:
        logging.error("File sorting failed") 