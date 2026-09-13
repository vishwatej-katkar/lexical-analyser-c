# Lexical Analyser
### `Before a compiler understands code, it has to recognize it.`

A C program that explores the first stage of compiler processing: breaking source text into meaningful lexical categories.

## From source code to tokens

Given:

```c
int count = 10;
```

the analyser can reason about the pieces as:

```text
int       → Keyword
count     → Identifier
=         → Operator
10        → Constant
;         → Special Character
```

## Token categories

The supplied implementation contains logic for recognizing:

- Keywords
- Identifiers
- Constants
- Preprocessor directives
- String literals
- Operators
- Special characters

The keyword/token definitions are kept separately from the main lexical-analysis logic.

## Processing model

```text
              C source file
                    |
                    v
              Read character
                    |
                    v
          +---------+---------+
          |         |         |
       identifier  number   special/
       /keyword    constant  operator
          |         |         |
          +---------+---------+
                    |
                    v
              Token output
```

## Project structure

```text
main.c
lexical_analyser.c
lexical_analyser.h
tokens.c
input_file.c
```

## Build

```bash
gcc main.c lexical_analyser.c tokens.c input_file.c -o lexical_analyser
```

Run using the input format expected by the supplied `main.c`.

## Why I kept this project

It creates a bridge between:

```text
C programming
      ↓
String/character processing
      ↓
Parsing
      ↓
Compiler fundamentals
```

## Interview angle

You can discuss:

- Keyword vs identifier detection
- Multi-character operators
- String-literal handling
- Preprocessor directives
- Why lexical analysis is different from syntax analysis
- How you would track line and column numbers

## Next iteration

- Add comment recognition.
- Add character constants.
- Improve numeric literal support.
- Handle all C multi-character operators.
- Report line/column numbers.
- Separate scanner state from output formatting.

`C` `Parsing` `Lexical Analysis` `Compiler Fundamentals` `String Processing`
