#include <ai.h>
#include "diffuse_bsdf.hpp"
 
AI_SHADER_NODE_EXPORT_METHODS(diffuse_method);
 
enum paramsList {
  diffuseColor
};
 
// static void Parameters(AtList* params, AtNodeEntry* nentry)
node_parameters {
  // it's supposedly more flexible to add metadata from a separate .mtd file
  // see: https://docs.arnoldrenderer.com/display/AFMUG/Creating+a+shader#CreatingaShader-1.2Creatingashader
  // TODO: figure out what maya.output_name and maya.output_shortname are for
  
  // the NULL here means to attach the metadata to the node itself (as opposed to some param entry)
  // see: https://trac.solidangle.com/arnoldpedia/chrome/site/Arnold-4.0.14.0/doc/api/group__ai__nodemeta.html
  AiMetaDataSetStr(nentry, NULL, "maya.name", "mynDiffuseMaya"); // name that appears in maya materials list
  AiMetaDataSetInt(nentry, NULL, "maya.id", 0x70000); // For personal use, put sth in range 0-0x7ffff
  AiMetaDataSetStr(nentry, NULL, "maya.classification", "shader/surface");

  // input param from maya. Assigned to the param enum in order
  AiParameterRGB("mynDiffuseColor", 0.9f, 0.2f, 0.2f);
}
 
// static void Initialize(AtNode* node)
node_initialize { (void)node; }
 
// static void Update(AtNode* node)
node_update { (void)node; }
 
// static void Finish(AtNode* node)
node_finish { (void)node; }
 
// static void Evaluate(AtNode* node, AtShaderGlobals* sg)
shader_evaluate {
  if (sg->Rt & AI_RAY_SHADOW) return;

  AtRGB color = AiShaderEvalParamRGB(diffuseColor);
  if (AiColorIsSmall(color)) return;

  sg->out.CLOSURE() = DiffuseBSDFCreate(sg, color, sg->Nf);
}
 
// AI_EXPORT_LIB bool NodeLoader(int i, AtNodeLib* node)
node_loader {
   if (i > 0)
      return false;
   node->methods     = diffuse_method;
   node->output_type = AI_TYPE_CLOSURE;
   node->name        = "mynDiffuse";
   node->node_type   = AI_NODE_SHADER;
   strcpy(node->version, AI_VERSION);
   return true;
}
