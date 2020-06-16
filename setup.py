# setup.py 
from setuptools import setup, Extension 
from pathlib import Path
source_files = [str(p) for p in Path('.').glob("*.cpp") ]

setup(name='stats', 
	ext_modules=[ 
			Extension('stats', 
					sources=source_files, 
					libraries=['boost_python38'],
					extra_compile_args=['-std=c++11'],
					language='c++',
					) 
			] 
) 
