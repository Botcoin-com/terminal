// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

#pragma once

#include "pch.h"
#include "AppearanceConfig.g.h"
#include "JsonUtils.h"
#include "../inc/cppwinrt_utils.h"
#include "IInheritable.h"

namespace winrt::Microsoft::Terminal::Settings::Model::implementation
{
    struct AppearanceConfig : AppearanceConfigT<AppearanceConfig>, IInheritable<AppearanceConfig>
    {
    public:
        AppearanceConfig();

        void LayerJson(const Json::Value& json);
        winrt::hstring ExpandedBackgroundImagePath();

        GETSET_SETTING(ConvergedAlignment, BackgroundImageAlignment, ConvergedAlignment::Horizontal_Center | ConvergedAlignment::Vertical_Center);

        GETSET_SETTING(hstring, ColorSchemeName, L"Campbell");
        GETSET_NULLABLE_SETTING(Windows::UI::Color, Foreground, nullptr);
        GETSET_NULLABLE_SETTING(Windows::UI::Color, Background, nullptr);
        GETSET_NULLABLE_SETTING(Windows::UI::Color, SelectionBackground, nullptr);
        GETSET_NULLABLE_SETTING(Windows::UI::Color, CursorColor, nullptr);
        GETSET_SETTING(Microsoft::Terminal::TerminalControl::CursorStyle, CursorShape, Microsoft::Terminal::TerminalControl::CursorStyle::Bar);
        GETSET_SETTING(hstring, BackgroundImagePath);

        GETSET_SETTING(double, BackgroundImageOpacity, 1.0);
        GETSET_SETTING(Windows::UI::Xaml::Media::Stretch, BackgroundImageStretchMode, Windows::UI::Xaml::Media::Stretch::UniformToFill);

    private:
    };
}

namespace winrt::Microsoft::Terminal::Settings::Model::factory_implementation
{
    BASIC_FACTORY(AppearanceConfig);
}