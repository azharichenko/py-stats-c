#/bin/bash
rm -rf *.so
rm -rf build/
python3 setup.py build_ext --inplace
python3 test.py
# pipenv run python3 -m pytest test.py
