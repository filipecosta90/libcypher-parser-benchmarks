

benchmark requirements
---------------

# install libcypher-parser

If you're using Mac OS X, libcypher-parser can be installed using homebrew:

```console
$ brew install cleishm/neo4j/libcypher-parser
```

or

```console
$ brew install cleishm/neo4j/cypher-lint
```

If you're using Ubuntu, libcypher-parser can be install using APT:

```console
$ sudo add-apt-repository ppa:cleishm/neo4j
$ sudo apt-get update
$ sudo apt-get install cypher-lint libcypher-parser-dev
```


# sample run ( cpu scaling needs to be turned off for real measurements )

```
libcypher-parser-benchmarks/build$ ./libcypher-parser-benchmarks --benchmark_min_time=10
2020-07-24T13:28:49+01:00
Running ./libcypher-parser-benchmarks
Run on (8 X 3900 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x4)
  L1 Instruction 32 KiB (x4)
  L2 Unified 256 KiB (x4)
  L3 Unified 6144 KiB (x1)
Load Average: 1.90, 1.56, 1.45
***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
-----------------------------------------------------------------------------
Benchmark                                   Time             CPU   Iterations
-----------------------------------------------------------------------------
BM_match_n_return_n                      9926 ns         9926 ns      1410184
BM_parse_parameters                     13827 ns        13827 ns      1025234
BM_merge_filter_with_parameters         94390 ns        94386 ns       149772
BM_merge_filter_without_parameters      74513 ns        74511 ns       184805
```