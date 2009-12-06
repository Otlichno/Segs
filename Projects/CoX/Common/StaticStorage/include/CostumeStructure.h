/*
 * Super Entity Game Server Project
 * http://segs.sf.net/
 * Copyright (c) 2006 Super Entity Game Server Team (see Authors.txt)
 * This software is licensed! (See License.txt for details)
 *
 * $Id$
 */

#pragma once
#include "types.h"
#include "CoXHash.h"
#include "DataStorage.h"
#include "ReadableStructures.h"
class BinReadable;
class CrcVisitor;
class ClassSchema;

struct GeoSetInfoEntry : public BinReadable
{
    DECL_READABLE(GeoSetInfoEntry);

    static void build_schema();

    std::string m_display_name;
    std::string m_geo_name;
    std::string m_geo;
    std::string m_tex1;
    std::string m_tex2;
    u32 m_devonly;
};
struct GeoSetMaskEntry : public BinReadable
{
    DECL_READABLE(GeoSetMaskEntry);

    static void build_schema();

    std::string m_display_name;
    std::string m_name;
};

struct GeoSetEntry : public BinReadable
{
    DECL_READABLE(GeoSetEntry);

    static void build_schema();

    std::string m_display_name;
    std::string m_body_part;
    u32 m_typename;
    std::vector<BinReadable *> m_mask_vals;
    std::vector<BinReadable *> m_mask_infos;
    std::vector<std::string> m_masks;
    std::vector<std::string> m_mask_names;
};

struct BoneSetEntry : public BinReadable
{
    DECL_READABLE(BoneSetEntry);

    static void build_schema();

    std::string m_name;
    std::string m_display_name;
    std::vector<BinReadable *> m_geoset;
};
struct RegionEntry : public BinReadable
{
    DECL_READABLE(RegionEntry);
    std::string m_name;
    std::string m_display_name;
    std::vector<BinReadable *> m_bonsets;
    static void build_schema();
};
struct OriginEntry : public BinReadable
{
    DECL_READABLE(OriginEntry);

    std::string m_name;
    std::vector<BinReadable *> m_body_palette; //color entries
    std::vector<BinReadable *> m_skin_palette;
    std::vector<BinReadable *> m_regions; // RegionEntries

    static void build_schema();
};
struct CostumeEntry  : public BinReadable
{
    DECL_READABLE(CostumeEntry);
    std::string m_name;
    std::vector<BinReadable *> m_origins;
    static void build_schema();
};
struct CostumeStorage : public BinReadable
{
    DECL_READABLE(CostumeStorage);
    std::vector<BinReadable *> m_costumes;
    static void build_schema();
};
