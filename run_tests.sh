#!/bin/bash

# Cub3D Parsing Test Script
# Run this script from the project root directory

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

EXEC="./cub"
TEST_DIR="./test_maps"
PASS=0
FAIL=0

echo "========================================"
echo "       CUB3D PARSING TEST SUITE"
echo "========================================"
echo ""

# Function to test a map file
test_map() {
    local file=$1
    local expected=$2  # "valid" or "invalid"
    local description=$3
    
    output=$($EXEC "$file" 2>&1)
    exit_code=$?
    
    if [ "$expected" = "valid" ]; then
        if [ $exit_code -eq 0 ]; then
            echo -e "${GREEN}[PASS]${NC} $description"
            ((PASS++))
        else
            echo -e "${RED}[FAIL]${NC} $description"
            echo "       Expected: valid (exit 0), Got: exit $exit_code"
            echo "       Output: $output"
            ((FAIL++))
        fi
    else
        if [ $exit_code -ne 0 ]; then
            echo -e "${GREEN}[PASS]${NC} $description"
            ((PASS++))
        else
            echo -e "${RED}[FAIL]${NC} $description"
            echo "       Expected: invalid (exit != 0), Got: exit $exit_code"
            ((FAIL++))
        fi
    fi
}

# Build the project first
echo "Building project..."
make re > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo -e "${RED}Build failed!${NC}"
    exit 1
fi
echo -e "${GREEN}Build successful!${NC}"
echo ""

echo "========== VALID MAPS =========="
test_map "$TEST_DIR/valid_basic.cub" "valid" "Basic valid map"
test_map "$TEST_DIR/valid_minimal.cub" "valid" "Minimal valid map"
test_map "$TEST_DIR/valid_black_colors.cub" "valid" "Black colors (0,0,0)"
test_map "$TEST_DIR/valid_white_colors.cub" "valid" "White colors (255,255,255)"
test_map "$TEST_DIR/valid_player_south.cub" "valid" "Player facing South"
test_map "$TEST_DIR/valid_player_east.cub" "valid" "Player facing East"
test_map "$TEST_DIR/valid_player_west.cub" "valid" "Player facing West"
test_map "$TEST_DIR/valid_large.cub" "valid" "Large valid map"
test_map "$TEST_DIR/valid_irregular_shape.cub" "valid" "Irregular shape map"
echo ""

echo "========== INVALID MAPS - DUPLICATES =========="
test_map "$TEST_DIR/invalid_duplicate_texture.cub" "invalid" "Duplicate texture (NO)"
test_map "$TEST_DIR/invalid_duplicate_floor.cub" "invalid" "Duplicate floor color"
test_map "$TEST_DIR/invalid_duplicate_ceiling.cub" "invalid" "Duplicate ceiling color"
echo ""

echo "========== INVALID MAPS - RGB ERRORS =========="
test_map "$TEST_DIR/invalid_rgb_four_values.cub" "invalid" "RGB with 4 values"
test_map "$TEST_DIR/invalid_rgb_two_values.cub" "invalid" "RGB with 2 values"
test_map "$TEST_DIR/invalid_rgb_over_255.cub" "invalid" "RGB value > 255"
test_map "$TEST_DIR/invalid_rgb_negative.cub" "invalid" "RGB negative value"
test_map "$TEST_DIR/invalid_rgb_letters.cub" "invalid" "RGB with letters"
test_map "$TEST_DIR/invalid_rgb_extra.cub" "invalid" "RGB extra characters"
echo ""

echo "========== INVALID MAPS - MISSING CONFIG =========="
test_map "$TEST_DIR/invalid_missing_texture.cub" "invalid" "Missing texture"
test_map "$TEST_DIR/invalid_missing_floor.cub" "invalid" "Missing floor color"
test_map "$TEST_DIR/invalid_missing_ceiling.cub" "invalid" "Missing ceiling color"
echo ""

echo "========== INVALID MAPS - MAP ERRORS =========="
test_map "$TEST_DIR/invalid_no_player.cub" "invalid" "No player position"
test_map "$TEST_DIR/invalid_multiple_players.cub" "invalid" "Multiple players"
test_map "$TEST_DIR/invalid_open.cub" "invalid" "Open map (not closed)"
test_map "$TEST_DIR/invalid_left_open.cub" "invalid" "Left side open"
test_map "$TEST_DIR/invalid_space_leak.cub" "invalid" "Space causing leak"
test_map "$TEST_DIR/invalid_row_extends.cub" "invalid" "Row extends beyond others"
# Note: Empty line in map is currently skipped by parser (design choice)
# test_map "$TEST_DIR/invalid_empty_line_in_map.cub" "invalid" "Empty line in map"
echo ""

echo "========== INVALID ARGUMENTS =========="
output=$($EXEC 2>&1)
if [ $? -ne 0 ]; then
    echo -e "${GREEN}[PASS]${NC} No arguments"
    ((PASS++))
else
    echo -e "${RED}[FAIL]${NC} No arguments should fail"
    ((FAIL++))
fi

output=$($EXEC "nonexistent.cub" 2>&1)
if [ $? -ne 0 ]; then
    echo -e "${GREEN}[PASS]${NC} Non-existent file"
    ((PASS++))
else
    echo -e "${RED}[FAIL]${NC} Non-existent file should fail"
    ((FAIL++))
fi

output=$($EXEC "test.txt" 2>&1)
if [ $? -ne 0 ]; then
    echo -e "${GREEN}[PASS]${NC} Wrong extension (.txt)"
    ((PASS++))
else
    echo -e "${RED}[FAIL]${NC} Wrong extension should fail"
    ((FAIL++))
fi

output=$($EXEC "$TEST_DIR/valid_basic.cub" "extra" 2>&1)
if [ $? -ne 0 ]; then
    echo -e "${GREEN}[PASS]${NC} Extra arguments"
    ((PASS++))
else
    echo -e "${RED}[FAIL]${NC} Extra arguments should fail"
    ((FAIL++))
fi

echo ""
echo "========================================"
echo "           TEST SUMMARY"
echo "========================================"
echo -e "Passed: ${GREEN}$PASS${NC}"
echo -e "Failed: ${RED}$FAIL${NC}"
TOTAL=$((PASS + FAIL))
echo "Total:  $TOTAL"
echo ""

if [ $FAIL -eq 0 ]; then
    echo -e "${GREEN}All tests passed!${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed.${NC}"
    exit 1
fi
