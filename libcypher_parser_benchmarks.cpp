/*
* Copyright 2020 Redis Labs Ltd. and Contributors
*
* This file is available under the Redis Labs Source Available License Agreement
*/

#include <benchmark/benchmark.h>
#include <cypher-parser.h>
#include <errno.h>
#include <stdio.h>

const char* match_n_cypher = "MATCH (n) RETURN n";
const size_t match_n_cypher_size = strlen(match_n_cypher);

const char* parse_params_cypher = "CYPHER p1Numeric=12345 p2Numeric=891807823 p3Text='Jon' p4Text='Doe' p5Numeric=12345 p6Numeric=164 p7Numeric=859 p8Numeric=83 p9Numeric=12345 p10Numeric=5 p11Bool='false' p12Numeric=84 p13Text='Jon Doe' p14Numeric=10";
const size_t parse_params_cypher_size = strlen(parse_params_cypher);

const char* merge_filter_with_parameters_cypher = "CYPHER p1Numeric=12345 p2Numeric=891807823 p3Text='Jon' p4Text='Doe' p5Numeric=12345 p6Numeric=164 p7Numeric=859 p8Numeric=83 p9Numeric=12345 p10Numeric=5 p11Bool='false' p12Numeric=84 p13Text='Jon Doe' p14Numeric=10 MERGE (u :UUU {p1Numeric: $p1Numeric, p9Numeric: $p1Numeric}) SET u.p2Numeric = $p2Numeric, u.p3Text = $p3Text, u.p4Text = $p4Text, u.p5Numeric = $p5Numeric, u.p6Numeric = $p6Numeric, u.p7Numeric = $p7Numeric, u.p8Numeric = $p8Numeric, u.p10Numeric = $p10Numeric, u.p11Bool = $p11Bool, u.p12Numeric = $p12Numeric, u.p13Text = $p13Text, u.p14Numeric = $p14Numeric";
const size_t merge_filter_with_parameters_cypher_size = strlen(merge_filter_with_parameters_cypher);

const char* merge_filter_without_parameters_cypher = "MERGE (u :UUU {p1Numeric: 12345, p9Numeric: 12345}) SET u.p2Numeric = 891807823, u.p3Text = 'Jon', u.p4Text = 'Doe', u.p5Numeric = 12345, u.p6Numeric = 164, u.p7Numeric = 859, u.p8Numeric = 83, u.p10Numeric = 5, u.p11Bool = 'false', u.p12Numeric = 84, u.p13Text = 'Jon Doe', u.p14Numeric = 10";
const size_t merge_filter_without_parameters_cypher_size = strlen(merge_filter_without_parameters_cypher);


static void BM_match_n_return_n(benchmark::State& state) {
  for (auto _ : state){
       cypher_parse_result_t *result = cypher_uparse(
            match_n_cypher, match_n_cypher_size, NULL, NULL, CYPHER_PARSE_ONLY_STATEMENTS);
        assert(result!=NULL);
  }
}

// 127.0.0.1:6379> graph.query q1 "CYPHER p1Numeric=12345 p2Numeric=891807823 p3Text='Jon' p4Text='Doe' p5Numeric=12345 p6Numeric=164 p7Numeric=859 p8Numeric=83 p9Numeric=12345 p10Numeric=5 p11Bool='false' p12Numeric=84 p13Text='Jon Doe' p14Numeric=10"
// (error) Error: empty query.
static void BM_parse_parameters(benchmark::State& state) {
  for (auto _ : state){
      
       cypher_parse_result_t *result = cypher_uparse(
            parse_params_cypher,parse_params_cypher_size, NULL, NULL, CYPHER_PARSE_ONLY_STATEMENTS);
        assert(result!=NULL);
  }
}


// 127.0.0.1:6379> graph.query q1 "CYPHER p1Numeric=12345 p2Numeric=891807823 p3Text='Jon' p4Text='Doe' p5Numeric=12345 p6Numeric=164 p7Numeric=859 p8Numeric=83 p9Numeric=12345 p10Numeric=5 p11Bool='false' p12Numeric=84 p13Text='Jon Doe' p14Numeric=10 MERGE (u :UUU {p1Numeric: $p1Numeric, p9Numeric: $p1Numeric}) SET u.p2Numeric = $p2Numeric, u.p3Text = $p3Text, u.p4Text = $p4Text, u.p5Numeric = $p5Numeric, u.p6Numeric = $p6Numeric, u.p7Numeric = $p7Numeric, u.p8Numeric = $p8Numeric, u.p10Numeric = $p10Numeric, u.p11Bool = $p11Bool, u.p12Numeric = $p12Numeric, u.p13Text = $p13Text, u.p14Numeric = $p14Numeric"
// 1) 1) "Labels added: 1"
//    2) "Nodes created: 1"
//    3) "Properties set: 14"
//    4) "Cached execution: 0"
//    5) "Query internal execution time: 10.928870 milliseconds"
static void BM_merge_filter_with_parameters(benchmark::State& state) {
  for (auto _ : state){
       cypher_parse_result_t *result = cypher_uparse(
            merge_filter_with_parameters_cypher, merge_filter_with_parameters_cypher_size, NULL, NULL, CYPHER_PARSE_ONLY_STATEMENTS);
        assert(result!=NULL);
  }
}

// 127.0.0.1:6379> graph.query q1 "MERGE (u :UUU {p1Numeric: 12345, p9Numeric: 12345}) SET u.p2Numeric = 891807823, u.p3Text = 'Jon', u.p4Text = 'Doe', u.p5Numeric = 12345, u.p6Numeric = 164, u.p7Numeric = 859, u.p8Numeric = 83, u.p10Numeric = 5, u.p11Bool = 'false', u.p12Numeric = 84, u.p13Text = 'Jon Doe', u.p14Numeric = 10"
// 1) 1) "Labels added: 1"
//    2) "Nodes created: 1"
//    3) "Properties set: 14"
//    4) "Cached execution: 0"
//    5) "Query internal execution time: 2.689901 milliseconds"
static void BM_merge_filter_without_parameters(benchmark::State& state) {
  for (auto _ : state){
       cypher_parse_result_t *result = cypher_uparse(
            merge_filter_without_parameters_cypher, merge_filter_without_parameters_cypher_size, NULL, NULL, CYPHER_PARSE_ONLY_STATEMENTS);
        assert(result!=NULL);
  }
}

// Register the functions as a benchmark
BENCHMARK(BM_match_n_return_n);
BENCHMARK(BM_parse_parameters);
BENCHMARK(BM_merge_filter_with_parameters);
BENCHMARK(BM_merge_filter_without_parameters);


BENCHMARK_MAIN();