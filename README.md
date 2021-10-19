# chemfiles-cli

This project provides the binary `cf` which functions as a simple CLI wrapper around the [chemfiles](https://github.com/chemfiles/chemfiles) library. Just provide the path to a file you would like to convert and a destination you would like to write it to. If the paths have valid extensions then their formats will be automatically detected. Otherwise, you can provide optional arguments to specify the input/output format independent of the file extension. Files with mutiple frames (such as trajectory files) are supported for all formats which have the capability to do so.

```
Usage: cf [options] [--] <src> <dst>
A simple chemistry file conversion CLI which wraps the chemfiles library

    -h, --help            show this help message and exit
    -v, --version         print version number and exit
    -i, --in-fmt=<str>    format of the input file
    -o, --out-fmt=<str>   format of the output file

Author: Seaton Ullberg <seatonullberg@gmail.com>
```

## Installation

> Currently, building directly from source is the only installation method, but precompiled packages for distribution are planned.

### Build from Source

This project uses git [submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules) and [cmake](https://cmake.org/) to manage dependencies.

```shell
$ git clone --recurse-submodules git@github.com:seatonullberg/chemfiles-cli.git
$ cd chemfiles-cli
$ mkdir build
$ cd build
$ cmake ..
$ make
$ make install
```

## License

Distributed under the BSD 3-Clause License. See [LICENSE](./LICENSE) for more information. 

## Acknowledgements

* [chemfiles](https://github.com/chemfiles/chemfiles) - Library for reading and writing chemistry files