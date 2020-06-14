#/bin/bash
rm -rf *.so
rm -rf build/

pipenv run python3 setup.py build_ext --inplace
pipenv run python3 -m pytest test.py