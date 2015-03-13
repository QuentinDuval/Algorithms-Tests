#include "EncodingTests.h"

#include "BitStream.h"
#include "HuffmanEncoding.h"
#include "RunLengthEncoding.h"

#include <cassert>
#include <iostream>


namespace algorithm
{
   void bitStreamTest()
   {
      BitStream stream;
      stream.writeBit(true);
      stream.writeBit(false);
      stream.writeChar('c');
      assert(true == stream.readBit());
      assert(false == stream.readBit());
      assert('c' == stream.readChar());
   }

   //--------------------------------------------------------------------------

   void runLengthEncodingTests()
   {
      std::cout << "[Tests] RunLengthEncoding (ratios)" << std::endl;

      RunLengthEncoding encoding;
      BitStream bitStream;
      size_t size = 100;

      std::cout << " - All ones: ";
      std::string allOnes(size, 0xff);
      encodeWith(encoding, allOnes, bitStream);
      std::cout << bitStream.toRead() / (8.0 * allOnes.size()) << std::endl;
      assert(allOnes == decodeWith(encoding, bitStream));

      std::cout << " - Half ones: ";
      std::string halfOnes(size, 0xf0);
      encodeWith(encoding, halfOnes, bitStream);
      std::cout << bitStream.toRead() / (8.0 * allOnes.size()) << std::endl;
      assert(halfOnes == decodeWith(encoding, bitStream));

      std::cout << " - Interleaved: ";
      std::string interverted(size, 0x55);
      encodeWith(encoding, interverted, bitStream);
      std::cout << bitStream.toRead() / (8.0 * allOnes.size()) << std::endl;
      assert(interverted == decodeWith(encoding, bitStream));
   }

   //--------------------------------------------------------------------------

   void huffmanEncodingTests()
   {
      HuffmanEncoding encoding;
      BitStream bitStream;

      std::cout << "[Tests] Huffman encoding (ratios)" << std::endl;

      //TODO - Bug in case the tree is made of one leaf at the top -> one type of char only
      //size_t size = 100;
      //std::cout << " - One character: ";
      //std::string oneChar(size, 'a');
      //encodeWith(encoding, oneChar, bitStream);
      //std::cout << bitStream.toRead() / (8.0 * oneChar.size()) << std::endl;
      //assert(oneChar == decodeWith(encoding, bitStream));

      size_t size = 100;
      std::cout << " - 2 characters: ";
      std::string twoChars = std::string(size / 2, 'a') + std::string(size / 2, 'b');
      encodeWith(encoding, twoChars, bitStream);
      std::cout << bitStream.toRead() / (8.0 * twoChars.size()) << std::endl;
      assert(twoChars == decodeWith(encoding, bitStream));

      std::cout << " - ADN: ";
      std::string adn = "ATACGCGTACGTAGCATCGCGTAATATTAGCTAGCATACGCGTACGTAGCATCGCGTAATATTAGCTAGCATACGCGTACGTAGCATCGCGTAATATTAA";
      encodeWith(encoding, adn, bitStream);
      std::cout << bitStream.toRead() / (8.0 * adn.size()) << std::endl;
      assert(adn == decodeWith(encoding, bitStream));

      std::cout << " - English sentence: ";
      std::string phr = "Let us try the huffman compression algorithm for a typical english language sentence like this one !";
      encodeWith(encoding, phr, bitStream);
      std::cout << bitStream.toRead() / (8.0 * phr.size()) << std::endl;
      assert(phr == decodeWith(encoding, bitStream));

      std::cout << " - Only different letters: ";
      std::string allDifferent;
      for (size_t i = 0; i < 100; ++i)
         allDifferent += 'a' + i - 1;
      encodeWith(encoding, allDifferent, bitStream);
      std::cout << bitStream.toRead() / (8.0 * allDifferent.size()) << std::endl;
      assert(allDifferent == decodeWith(encoding, bitStream));
   }
}
