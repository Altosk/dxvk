#pragma once

#include "d3d9_include.h"

namespace dxvk {

  constexpr uint32_t HardwareCursorWidth     = 32u;
  constexpr uint32_t HardwareCursorHeight    = 32u;
  constexpr uint32_t HardwareCursorFormatSize = 4u;
  constexpr uint32_t HardwareCursorPitch      = HardwareCursorWidth * HardwareCursorFormatSize;

  // Format Size of 4 bytes (ARGB)
  using CursorBitmap = uint8_t[HardwareCursorHeight * HardwareCursorPitch];

  class D3D9Cursor {

  public:

    void UpdateCursor(int X, int Y);

    int PrevPosX;
    int PrevPosY;

    BOOL ShowCursor(BOOL bShow);

    HRESULT SetHardwareCursor(UINT XHotSpot, UINT YHotSpot, const CursorBitmap& bitmap);

  private:

    BOOL    m_visible       = FALSE;

    HCURSOR m_hCursor       = nullptr;

  };

}
