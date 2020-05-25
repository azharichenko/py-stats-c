# setup.py 
from distutils.core import setup, Extension 

setup(name='stats', 
	ext_modules=[ 
			Extension('stats', 
					sources=['ext/statistics.c'], 
					) 
			] 
) 
