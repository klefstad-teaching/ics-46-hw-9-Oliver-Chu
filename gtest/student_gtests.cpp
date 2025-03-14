#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

TEST(Dijkstras, path) {
    Graph G;
    std::stringstream out;
    file_to_graph("/home/ojchu/ICS46/HW9/src/small.txt", G);
    vector<int> previous(G.numVertices);
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    for (int num = 0; num < G.numVertices; ++num) {
        vector<int> path = extract_shortest_path(distances, previous, num);
        for (auto vert : path) {
          out << vert << " ";
        }
        out << endl;
    }
  EXPECT_STREQ(out.str().c_str(), "0 \n0 3 1 \n0 3 1 2 \n0 3 \n");
}

TEST(Dijkstras, weight) {
    Graph G;
    std::stringstream out;
    file_to_graph("/home/ojchu/ICS46/HW9/src/small.txt", G);
    vector<int> previous(G.numVertices);
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    for (int num = 0; num < G.numVertices; ++num) {
        vector<int> path = extract_shortest_path(distances, previous, num);
        out << distances[num] << " ";
    }
    EXPECT_STREQ(out.str().c_str(), "0 3 6 1 ");
}

TEST(Ladder, Adjacent1) {
    EXPECT_TRUE(is_adjacent("hello", "bello"));
}

TEST(Ladder, Adjacent2) {
    EXPECT_TRUE(is_adjacent("hello", "helloo"));
}

TEST(Ladder, Adjacent3) {
    EXPECT_TRUE(is_adjacent("a", "b"));
}

TEST(Ladder, Adjacent4) {
    EXPECT_FALSE(is_adjacent("hello", "hellooo"));
}

TEST(Ladder, Adjacent5) {
    EXPECT_FALSE(is_adjacent("hello", "belloo"));
}

TEST(Ladder, confirm1) {
    set<string> word_list;
    load_words(word_list, "/home/ojchu/ICS46/HW9/src/words.txt");
    EXPECT_EQ(generate_word_ladder("cat", "dog", word_list).size(), 4);
}

TEST(Ladder, confirm2) {
    set<string> word_list;
    load_words(word_list, "/home/ojchu/ICS46/HW9/src/words.txt");
    EXPECT_EQ(generate_word_ladder("marty", "curls", word_list).size(), 6);
}

TEST(Ladder, confirm3) {
    set<string> word_list;
    load_words(word_list, "/home/ojchu/ICS46/HW9/src/words.txt");
    EXPECT_EQ(generate_word_ladder("code", "data", word_list).size(), 6);
}

TEST(Ladder, confirm4) {
    set<string> word_list;
    load_words(word_list, "/home/ojchu/ICS46/HW9/src/words.txt");
    EXPECT_EQ(generate_word_ladder("work", "play", word_list).size(), 6);
}

TEST(Ladder, confirm5) {
    set<string> word_list;
    load_words(word_list, "/home/ojchu/ICS46/HW9/src/words.txt");
    EXPECT_EQ(generate_word_ladder("sleep", "awake", word_list).size(), 8);
}

TEST(Ladder, confirm6) {
    set<string> word_list;
    load_words(word_list, "/home/ojchu/ICS46/HW9/src/words.txt");
    EXPECT_EQ(generate_word_ladder("car", "cheat", word_list).size(), 4);
}