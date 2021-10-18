# chemfiles-cli

This tool is really as simple as can be! Just provide the path to a file you would like to convert and a destination you would like to write it to. If the paths have valid extensions then their formats will be automatically detected. Otherwise, you can provide optional arguments to inform the tool of the input/output format independent of the file extension. Files with mutiple frames (such as trajectory file) are supported for all formats which have the capability to do so.

```
Usage: cf [options] [--] <src> <dst>
A simple chemistry file conversion CLI which wraps the chemfiles library

    -h, --help            show this help message and exit
    -i, --in-fmt=<str>    format of the input file
    -o, --out-fmt=<str>   format of the output file

Author: Seaton Ullberg <seatonullberg@gmail.com>
Version: 0.1.0
```

# License

Distributed under the BSD 3-Clause License. See [LICENSE](./LICENSE) for more information. 

# Acknowledgements

* [chemfiles](https://github.com/chemfiles/chemfiles) - Library for reading and writing chemistry files