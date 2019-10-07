#pragma once
 
#include <ai_shader_bsdf.h>
#include <ai_shaderglobals.h>
 
static void Init(const AtShaderGlobals* shader_global, AtBSDF* bsdf);

static AtBSDFLobeMask Sample(const AtBSDF* bsdf,
                             const AtVector rnd,
                             const float wavelength,
                             const AtBSDFLobeMask lobe_mask,
                             const bool need_pdf,
                             AtVectorDv& out_wi,
                             int& out_lobe_index,
                             AtBSDFLobeSample out_lobes[]);

static AtBSDFLobeMask Eval(const AtBSDF* bsdf,
                           const AtVector& wi,
                           const AtBSDFLobeMask lobe_mask,
                           const bool need_pdf,
                           AtBSDFLobeSample out_lobes[]);

AtBSDF* DiffuseBSDFCreate(const AtShaderGlobals* sg, const AtRGB& weight, const AtVector& N);
