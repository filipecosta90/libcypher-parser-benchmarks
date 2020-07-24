

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

# sample run

```
libcypher-parser-benchmarks/build$ ./libcypher-parser-benchmarks --benchmark_min_time=10
2020-07-24T15:27:29+01:00
Running ./libcypher-parser-benchmarks
Run on (8 X 3900 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x4)
  L1 Instruction 32 KiB (x4)
  L2 Unified 256 KiB (x4)
  L3 Unified 6144 KiB (x1)
Load Average: 1.29, 1.49, 1.44
-------------------------------------------------------------------------------------------------------
Benchmark                                                             Time             CPU   Iterations
-------------------------------------------------------------------------------------------------------
BM_cypher_uparse_NODES__match_n_return_n                          10193 ns        10192 ns      1406925
BM_cypher_uparse_NODES__parameters                                14393 ns        14393 ns       941563
BM_cypher_uparse_NODES__merge_filter_with_parameters              92863 ns        92861 ns       151409
BM_cypher_uparse_NODES__merge_filter_without_parameters           78000 ns        77997 ns       190801
BM_cypher_uparse_EDGES__parameters                                31386 ns        31385 ns       437308
BM_cypher_uparse_EDGES__merge_fiter_edges_with_parameters         52388 ns        52387 ns       273616
BM_cypher_uparse_EDGES__merge_fiter_edges_without_parameters     393600 ns       393590 ns        36470
```