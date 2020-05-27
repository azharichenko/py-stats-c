# setup.py 
from distutils.core import setup, Extension 
from pathlib import Path
source_files = [str(p) for p in Path('./ext').glob("*.cpp") ]

setup(name='stats', 
	ext_modules=[ 
			Extension('stats', 
					sources=source_files, 
					) 
			] 
) 
