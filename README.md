<div align="center">
  <img src="logo.svg" width="600" alt="Logo"/>
</div>

---

A simple implementation of some functions that can be used for AI development like linear regression, a data-parser and a minimal tensor implementation.

Inspired by the [pytorch Python package](https://github.com/pytorch/pytorch), definetly also the name :)

## Features
- Small tensor module
- Module methods to use linear regression with:
  - CSV file parser
  - Examples implementation

## Installation
1. Navigate to the folder to hold the code: `cd disired/path/here`
2. Clone the repo: `git clone https://github.com/mp3skater/ctorch.git`

Info: cmake and gcc need to be installed, more info [here](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html)

## Usage
#### For the main module
1. Look at the `src/test.c` file to see the implementation.
2. To execute write: `make run`

#### For tensor module
1. Look at the `tensor/test.c` file to see the implementation.
2. To execute write: `make tensor`

## License
This project is licensed under the [MIT License](LICENSE.md)
