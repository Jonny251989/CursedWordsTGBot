#include "test.h"

void ParserTest::SetUp() {

}

void ParserTest::TearDown() {

}

TEST_F(ParserTest, ExeptionInvalidArgument_1) {
  
Parser parser{{"-token", "-list", "-number"}};
  EXPECT_THROW(parser.parse_string("-token-list-number"), std::invalid_argument);
}

TEST_F(ParserTest, ExeptionInvalidArgument_2) {
  
Parser parser{{"-token", "-list", "-number"}};
  EXPECT_THROW(parser.parse_string("-token-list #4lkdsd"), std::invalid_argument);
}

TEST_F(ParserTest, ExeptionInvalidArgument_3) {
  
Parser parser{{"-token", "-list", "-number"}};
  EXPECT_THROW(parser.parse_string("-token 23f84 -list #4lkdsd -number ds234 -key 7dsf023"), std::invalid_argument);
}

TEST_F(ParserTest, ExeptionInvalidArgument_4) {
  
Parser parser{{"-token", "-list"}};
  EXPECT_THROW(parser.parse_string("-token 23f84 -list #4lkdsd -number ds234"), std::invalid_argument);
}

TEST_F(ParserTest, ExeptionInvalidArgument_5) {
  
Parser parser{{"-token", "-list", "-number"}};
  EXPECT_THROW(parser.parse_string("23f84 -list #4lkdsd -number ds234"), std::invalid_argument);
}



TEST_F(ParserTest, Size) {
  
  Parser parser{{"-token", "-list", "-number"}};

  auto str_parse = parser.parse_string("-token 23fsf3 -list se_df35=_14 -number +24rf$dsvcx");

    EXPECT_EQ(str_parse.size(), 3);
}

TEST_F(ParserTest, RemoveSpaces) {
  
  Parser parser{{"-token", "-list", "-number"}};
  
  std::string str = "-list           +24rf$dsvcx -token                     7229787403:AAH0DVCx0wUQ-G9lkXYoIllHL0DhmdawEZo       -number            AAH0;3!=Cx-0w+UQ";
  parser.remove_spaces(str);

    EXPECT_EQ(str,  "-list +24rf$dsvcx -token 7229787403:AAH0DVCx0wUQ-G9lkXYoIllHL0DhmdawEZo -number AAH0;3!=Cx-0w+UQ");
}


TEST_F(ParserTest, EqualOfArguments) {
  
  Parser parser{{"-token", "-list", "-number"}};
  
  std::unordered_map<std::string, std::string> value_of_tokens = parser.parse_string("-token 3jfd0s34f_fdsf -list 74322342 -number _234kfsfe");

  std::vector<std::pair<std::string, std::string>>vector_of_compare{{"-token", "3jfd0s34f_fdsf"},{"-list","74322342"},{"-number", "_234kfsfe"}};
  
  size_t i = vector_of_compare.size() - 1;

  for(const auto& [key, value] : value_of_tokens){
    EXPECT_EQ( key, vector_of_compare[i].first );
    EXPECT_EQ( value, vector_of_compare[i].second );
    i--;
  }

}