#include "StringTrieTests.h"

#include "StringTrie.h"
#include "utils/Algorithms.h"
#include "utils/Timer.h"

#include <assert.h>
#include <iostream>


namespace algorithm
{
   void stringTrieSetTests()
   {
      StringTrieSet t;
      auto inputs = { "alpha", "beta", "alpha-numeric" };
      
      for (auto& s : inputs) assert(true == t.insert(s));
      for (auto& s : inputs) assert(true == t.search(s));
      for (auto& s : inputs) assert(false == t.insert(s));
      assert(3 == t.size());

      assert(false == t.search("a"));
      assert(false == t.search("alpha-"));

      for (auto& s : inputs) assert(true == t.remove(s));
      assert(0 == t.size());

      for (auto& s : inputs) assert(true == t.insert(s));
      for (auto& s : inputs) assert(true == t.search(s));
   }

   void stringTrieMapTests()
   {
      StringTrie<int> t;
      auto keys = std::vector<std::string>{ "alpha", "beta", "alpha-numeric" };
      auto vals = std::vector<int>        { 1, 2, 3 };

      for (size_t i = 0; i < keys.size(); ++i)
         t.insert(keys[i], vals[i]);
      assert(3 == t.size());

      for (size_t i = 0; i < keys.size(); ++i)
         assert(vals[i] == *t.search(keys[i]));

      assert(nullptr == t.search("a"));
      assert(nullptr == t.search("alpha-"));

      assert("alpha" == t.longestPrefixOf("alpha-"));
      assert("alpha" == t.longestPrefixOf("alphab"));
      assert("" == t.longestPrefixOf("alph"));

      for (auto& s : keys) assert(true == t.remove(s));
      assert(0 == t.size());
   }

   void stringTrieTests()
   {
      stringTrieSetTests();
      stringTrieMapTests();
   }

   //--------------------------------------------------------------------------

   void stringTriePerfTests()
   {
      size_t dim = 1000000;
      std::vector<std::string> strings(dim);
      for (size_t i = 0; i < dim; ++i)
      {
         for (size_t j = i; j != 0; j /= UCHAR_MAX)
            strings[i] += ('a' + j - 1);
      }
      utils::shuffle(strings);

      std::cout << std::endl << "[String trie timings]" << std::endl;
      StringTrieSet t;

      std::cout << "* Inserts" << std::endl;
      utils::showTime(std::cout, [&]() { for (auto& s : strings) t.insert(s); });

      std::cout << "* Searches" << std::endl;
      utils::showTime(std::cout, [&]() { for (auto& s : strings) t.search(s); });

      std::cout << "* Removals" << std::endl;
      utils::showTime(std::cout, [&]() { for (auto& s : strings) t.remove(s); });
   }
}
