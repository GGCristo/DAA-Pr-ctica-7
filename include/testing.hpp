#pragma once

#include <memory>
#include "data.hpp"
#include "solution.hpp"
#include "greedy_time.hpp"
#include "greedy_TCT.hpp"
#include "multiboot.hpp"
#include "gvns.hpp"

// Wrapper
void testing();

// Greedy
void testing_greedyTime();
void testing_greedyTct();

// MultiBoot
void testing_reinsert(int, bool = false);
void testing_move(int, bool = false);
void testin_innerSwap(int, bool = false);
void testing_extraSwap(int, bool = false);

// GVNS
void testing_gvnsReInsertAndMove(int, bool = false);
void testing_gvnsReInsertAndExtraSwap(int, bool = false);
void testing_gvnsExtraSwapAndMove(int, bool = false);
void testing_gvnsExtraSwapAndExtraSwap(int, bool = false);
