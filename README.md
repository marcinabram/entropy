# Entropy

Calculate entropy of binary signal.

Compare speed of python and c++ solutions.

## C++

### To run tests

    make test

### To run demo

    make compile
    time ./demo.x signal.dat 2

## Python

### To install dependencies

    pip install -r requirements.txt


### To run tests

    PYTHONPATH=./ py.test tests/

    nosetests tests/

    PYTHONPATH=./ python tests/entropy_test.py

    coverage run --source='.' -m unittest discover tests "*_test.py"

    coverage report -m --omit=,"tests/*","*/config.py","*/__init__.py","setup.py","env/*","demo.py" --fail-under=100


### To run demo

    python generate_random_signal.py
    time python demo.py -w 2


### Examples

To see more examples, cf. notebooks folder.
