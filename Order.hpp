#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <memory>
#include <cmath>
#include <limits>
#include <cassert>
#include <stdexcept>      
#include <cstdint>
#include <chrono>
#include <string>

enum class OrderType {
    MARKET,
    LIMIT,
    FOK, // Fill or Kill
    IOC,  // Immediate or Cancel
    GTC,   // Good Till Cancelled    
};

enum class OrderSide {
    BUY,
    SELL
};

enum class OrderStatus {
    PENDING,
    COMPLETED,
    CANCELLED
};

#include <cstdint>
#include <chrono>
#include <string>

// Enumerations for order properties
enum class OrderSide { BUY, SELL };
enum class OrderType { LIMIT, MARKET, STOP, STOP_LIMIT };
enum class OrderStatus { NEW, PARTIAL, FILLED, CANCELED };

struct Order {
    // Core Fields
    uint64_t orderId;                 // Unique identifier for the order
    OrderSide side;                   // BUY or SELL
    uint64_t price;                   // Price in smallest currency unit (e.g., cents)
    uint32_t quantity;                // Total quantity
    OrderType type;                   // Type of order: LIMIT, MARKET, etc.
    std::chrono::steady_clock::time_point timestamp; // Order creation time

    Order(uint64_t id,
          OrderSide side,
          uint64_t price,
          uint32_t qty,
          OrderType type)
        : orderId(id),
          side(side),
          price(price),
          quantity(qty),
          type(type),
          timestamp(std::chrono::steady_clock::now())
    {}
    
};