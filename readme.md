# cw::string

Encoding-aware string class with UTF-8 and ASCII encoding schemes.

Work in progress.

## Concepts

* Alphabet -- a set of elements called symbols
* Symbol -- an element of an alphabet
* String -- a sequence of symbols from a given alphabet
* Encoding -- represents an abstract string as a sequence of data units (e.g. bytes)

## Classes

* String -- stores a sequence of units
* String View -- interprets a subsequence of units stored elsewhere

## Key Operations

* Iterate over unit sequence
* Iterate over symbol sequence
* Convert between two different encodings of the same alphabet, e.g. UTF-8 <--> UTF-32

