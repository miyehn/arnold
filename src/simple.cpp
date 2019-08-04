#include <ai.h>
#include "diffuse_bsdf.h"
 
AI_SHADER_NODE_EXPORT_METHODS(simpleMethods);
 
enum simpleParams { p_color };
 
node_parameters
{
   AiParameterRGB("color", 0.7f, 0.7f, 0.7f);
}
 
node_initialize
{
}
 
node_update
{
}
 
node_finish
{
}
 
shader_evaluate
{
  if (sg->Rt & AI_RAY_SHADOW) return;

  AtRGB color = AiShaderEvalParamRGB(p_color);
  if (AiColorIsSmall(color)) return;

  sg->out.CLOSURE() = DiffuseBSDFCreate(sg, color, sg->Nf);
}
 
node_loader
{
   if (i > 0)
      return false;
   node->methods     = simpleMethods;
   node->output_type = AI_TYPE_CLOSURE;
   node->name        = "simple";
   node->node_type   = AI_NODE_SHADER;
   strcpy(node->version, AI_VERSION);
   return true;
}
