#include "test_runner.h"
#include <cstddef>
#include <cstdint>

struct Nucleotide {
    char Symbol;
    size_t Position;
    int ChromosomeNum;
    int GeneNum;
    bool IsMarked;
    char ServiceInfo;
};

struct CompactNucleotide {
    uint32_t Position;
    uint16_t GeneNum:15;
    uint16_t IsMarked:1;
    uint8_t Symbol:2;
    uint8_t ChromosomeNum:6;
    char ServiceInfo;
};

bool operator == (const Nucleotide& lhs, const Nucleotide& rhs) {
    return (lhs.Symbol == rhs.Symbol)
            && (lhs.Position == rhs.Position)
            && (lhs.ChromosomeNum == rhs.ChromosomeNum)
            && (lhs.GeneNum == rhs.GeneNum)
            && (lhs.IsMarked == rhs.IsMarked)
            && (lhs.ServiceInfo == rhs.ServiceInfo);
}

CompactNucleotide nucleo(const Nucleotide& nucleo) {
    CompactNucleotide result;
    result.Position = nucleo.Position;
    result.GeneNum = nucleo.GeneNum;
    result.IsMarked = nucleo.IsMarked;
    result.ChromosomeNum = nucleo.ChromosomeNum;
    result.ServiceInfo = nucleo.ServiceInfo;

    switch (nucleo.Symbol) {
        case 'A':
            result.Symbol = 0; break;
        case 'T':
            result.Symbol = 1; break;
        case 'G':
            result.Symbol = 2; break;
        case 'C':
            result.Symbol = 3; break;
        default:
            throw "Impossible value of Nucleotide symbol";
    }

    return result;
};

Nucleotide Decompress(const CompactNucleotide& nucleo) {
    Nucleotide result;
    result.Position = nucleo.Position;
    result.GeneNum = nucleo.GeneNum;
    result.IsMarked = nucleo.IsMarked;
    result.ChromosomeNum = nucleo.ChromosomeNum;
    result.ServiceInfo = static_cast<uint32_t>nucleo.ServiceInfo;

    switch (nucleo.Symbol) {
        case 0:
            result.Symbol = 'A'; break;
        case 1:
            result.Symbol = 'T'; break;
        case 2:
            result.Symbol = 'G'; break;
        case 3:
            result.Symbol = 'C'; break;
        default:
            throw "Impossible value of Nucleotide symbol";
    }
    return result;
}

void TestSize() {
    ASSERT(sizeof(CompactNucleotide) <= 8);
}

void TestCompressDecompress() {
    Nucleotide source;

    source.Symbol = 'T';
    source.Position = 1'000'000'000;
    source.ChromosomeNum = 48;
    source.GeneNum = 1'000;
    source.IsMarked = true;
    source.ServiceInfo = 'Test';

    CompactNucleotide compressedSource = nucleo(source);
    Nucleotide decompressedSource = Decompress(compressedSource);

    ASSERT(source == decompressedSource);
}

int main() {
    TestRunner tr;

    RUN_TEST(tr, TestSize);
    RUN_TEST(tr, TestCompressDecompress);

    return 0;
}
