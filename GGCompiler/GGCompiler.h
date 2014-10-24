#pragma once

enum GGTokenType {
  TOKEN_NONE,

  TOKEN_DISCARD,
  TOKEN_EOF,
  TOKEN_END_OF_LINE,
  TOKEN_WHITESPACE,
  TOKEN_COMMENT,
  TOKEN_TYPE_IDENTIFIER,
  TOKEN_IDENTIFIER,
  TOKEN_LLVM_CONTENT,

  //TOKEN_SEMICOLON,
  //TOKEN_DECLARATION_ASSIGNMENT,

  TOKEN_LITERAL_INTEGER,
  TOKEN_LITERAL_FLOAT,
  TOKEN_LITERAL_STRING,

  TOKEN_UNARY_OPERATOR,
  TOKEN_BINARY_OPERATOR,
  TOKEN_POSTFIX_OPERATOR,
  TOKEN_ASSIGNMENT_OPERATOR,

  TOKEN_ARRAY_SUBSCRIPT,

  TOKEN_COMPOUND,

  TOKEN_COMPOUND_PROGRAM,

  TOKEN_COMPOUND_VARIABLE_DEFINITION,
  //TOKEN_COMPOUND_GLOBAL_VARIABLE,


  //TOKEN_COMPOUND_LITERAL_INTEGER,

  TOKEN_COMPOUND_FUNCTION_DEFINITION,
  TOKEN_COMPOUND_FUNCTION_PARAMS,
  TOKEN_COMPOUND_FUNCTION_PARAM,
  TOKEN_COMPOUND_FUNCTION_BODY,

  TOKEN_COMPOUND_UNARY_OPERATION,
  TOKEN_COMPOUND_BINARY_OPERATION,
  TOKEN_COMPOUND_ARRAY_INDEX,
  TOKEN_COMPOUND_UNARY_POST_OPERATION,
  TOKEN_COMPOUND_MEMBER_IDENTIFIER,
  TOKEN_COMPOUND_FUNCTION_CALL,
  TOKEN_COMPOUND_FUNCTION_CALL_PARAMS,

  TOKEN_COMPOUND_INLINE_LLVM,

  TOKEN_COMPOUND_POINTER_TYPE,
  TOKEN_COMPOUND_ARRAY_TYPE,
  TOKEN_COMPOUND_FUNCTION_TYPE,
  TOKEN_COMPOUND_PARAM_TYPE_LIST,
  TOKEN_COMPOUND_EXTERNAL_FUNCTION_DECLARATION,

  TOKEN_COMPOUND_EXPRESSION_STATEMENT,
  TOKEN_COMPOUND_BLOCK_STATEMENT,

  TOKEN_COMPOUND_ASSIGNMENT_STATEMENT,

  TOKEN_COMPOUND_IF_STATEMENT,
  TOKEN_COMPOUND_FOR_STATEMENT,
  TOKEN_COMPOUND_RETURN_STATEMENT,

  TOKEN_COMPOUND_TYPEDEF_DEFINITION,

  TOKEN_COMPOUND_LLVM_TYPE_DEFINITION,

  TOKEN_COMPOUND_STRUCT_DEFINITION,
  TOKEN_COMPOUND_STRUCT_FIELDS,

  TOKEN_COMPOUND_ENUM_DEFINITION,
  TOKEN_COMPOUND_ENUM_FIELDS,
};

struct GGParseInfo {
  int line_number;
  int col_number;
};

struct GGSubString {
  const char *start;
  int length;
};

struct GGToken {
  GGTokenType token;
  GGParseInfo info;
  GGSubString substring;

  GGToken *subtokens;
  int num_subtokens;

  const char *next;
};

GGToken GGCompile(const char *file_data);


