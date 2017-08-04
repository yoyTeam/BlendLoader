#ifndef _Blender_h_
#define _Blender_h_
// Generated from a Blender(264) file.

#ifdef near
#undef near
#endif
#ifdef far
#undef far
#endif
#ifdef rad2
#undef rad2
#endif


namespace Blender {

struct Link;
struct LinkData;
struct ListBase;
struct vec2s;
struct vec2f;
struct vec3f;
struct rcti;
struct rctf;
struct IDPropertyData;
struct IDProperty;
struct ID;
struct Library;
struct PreviewImage;
struct IpoDriver;
struct IpoCurve;
struct Ipo;
struct KeyBlock;
struct Key;
struct TextLine;
struct Text;
struct PackedFile;
struct GPUDOFSettings;
struct GPUSSAOSettings;
struct GPUFXSettings;
struct Camera;
struct ImageUser;
struct RenderSlot;
struct Image;
struct MTex;
struct CBData;
struct ColorBand;
struct EnvMap;
struct PointDensity;
struct VoxelData;
struct OceanTex;
struct Tex;
struct TexMapping;
struct ColorMapping;
struct Lamp;
struct VolumeSettings;
struct GameSettings;
struct TexPaintSlot;
struct Material;
struct VFont;
struct MetaElem;
struct MetaBall;
struct BezTriple;
struct BPoint;
struct Nurb;
struct CharInfo;
struct TextBox;
struct EditNurb;
struct Curve;
struct Mesh;
struct TFace;
struct MFace;
struct MEdge;
struct MDeformWeight;
struct MDeformVert;
struct MVert;
struct MCol;
struct MPoly;
struct MLoop;
struct MTexPoly;
struct MLoopUV;
struct MLoopCol;
struct MSelect;
struct MTFace;
struct MFloatProperty;
struct MIntProperty;
struct MStringProperty;
struct OrigSpaceFace;
struct OrigSpaceLoop;
struct MDisps;
struct MultiresCol;
struct MultiresColFace;
struct MultiresFace;
struct MultiresEdge;
struct MultiresLevel;
struct Multires;
struct MRecast;
struct GridPaintMask;
struct MVertSkin;
struct FreestyleEdge;
struct FreestyleFace;
struct ModifierData;
struct MappingInfoModifierData;
struct SubsurfModifierData;
struct LatticeModifierData;
struct CurveModifierData;
struct BuildModifierData;
struct MaskModifierData;
struct ArrayModifierData;
struct MirrorModifierData;
struct EdgeSplitModifierData;
struct BevelModifierData;
struct SmokeModifierData;
struct DisplaceModifierData;
struct UVProjectModifierData;
struct DecimateModifierData;
struct SmoothModifierData;
struct CastModifierData;
struct WaveModifierData;
struct ArmatureModifierData;
struct HookModifierData;
struct SoftbodyModifierData;
struct ClothModifierData;
struct CollisionModifierData;
struct SurfaceModifierData;
struct BooleanModifierData;
struct MDefInfluence;
struct MDefCell;
struct MeshDeformModifierData;
struct ParticleSystemModifierData;
struct ParticleInstanceModifierData;
struct ExplodeModifierData;
struct MultiresModifierData;
struct FluidsimModifierData;
struct ShrinkwrapModifierData;
struct SimpleDeformModifierData;
struct ShapeKeyModifierData;
struct SolidifyModifierData;
struct ScrewModifierData;
struct OceanModifierData;
struct WarpModifierData;
struct WeightVGEditModifierData;
struct WeightVGMixModifierData;
struct WeightVGProximityModifierData;
struct DynamicPaintModifierData;
struct RemeshModifierData;
struct SkinModifierData;
struct TriangulateModifierData;
struct LaplacianSmoothModifierData;
struct UVWarpModifierData;
struct MeshCacheModifierData;
struct LaplacianDeformModifierData;
struct WireframeModifierData;
struct DataTransferModifierData;
struct NormalEditModifierData;
struct EditLatt;
struct Lattice;
struct bDeformGroup;
struct BoundBox;
struct LodLevel;
struct Object;
struct ObHook;
struct DupliObject;
struct PartDeflect;
struct EffectorWeights;
struct PTCacheExtra;
struct PTCacheMem;
struct PointCache;
struct SBVertex;
struct BulletSoftBody;
struct SoftBody;
struct FluidVertexVelocity;
struct FluidsimSettings;
struct World;
struct Base;
struct AviCodecData;
struct QuicktimeCodecData;
struct QuicktimeCodecSettings;
struct FFMpegCodecData;
struct AudioData;
struct SceneRenderLayer;
struct ImageFormatData;
struct BakeData;
struct RenderData;
struct RenderProfile;
struct GameDome;
struct GameFraming;
struct RecastData;
struct GameData;
struct TimeMarker;
struct Paint;
struct ImagePaintSettings;
struct ParticleBrushData;
struct ParticleEditSettings;
struct Sculpt;
struct UvSculpt;
struct VPaint;
struct TransformOrientation;
struct UnifiedPaintSettings;
struct MeshStatVis;
struct ToolSettings;
struct bStats;
struct UnitSettings;
struct PhysicsSettings;
struct DisplaySafeAreas;
struct Scene;
struct BGpic;
struct RegionView3D;
struct View3D;
struct View2D;
struct SpaceLink;
struct SpaceInfo;
struct SpaceButs;
struct SpaceOops;
struct SpaceIpo;
struct SpaceNla;
struct SpaceTimeCache;
struct SpaceTime;
struct SpaceSeq;
struct MaskSpaceInfo;
struct FileSelectParams;
struct SpaceFile;
struct FSMenuEntry;
struct SpaceImage;
struct SpaceText;
struct Script;
struct SpaceScript;
struct bNodeTreePath;
struct SpaceNode;
struct SpaceLogic;
struct ConsoleLine;
struct SpaceConsole;
struct SpaceUserPref;
struct SpaceClip;
struct uiFont;
struct uiFontStyle;
struct uiStyle;
struct uiWidgetColors;
struct uiWidgetStateColors;
struct uiPanelColors;
struct uiGradientColors;
struct ThemeUI;
struct ThemeSpace;
struct ThemeWireColor;
struct bTheme;
struct bAddon;
struct bPathCompare;
struct SolidLight;
struct WalkNavigation;
struct UserDef;
struct bScreen;
struct ScrVert;
struct ScrEdge;
struct Panel;
struct PanelCategoryStack;
struct uiList;
struct uiPreview;
struct ScrArea;
struct ARegion;
struct FileGlobal;
struct StripElem;
struct StripCrop;
struct StripTransform;
struct StripColorBalance;
struct StripProxy;
struct Strip;
struct Sequence;
struct MetaStack;
struct Editing;
struct WipeVars;
struct GlowVars;
struct TransformVars;
struct SolidColorVars;
struct SpeedControlVars;
struct GaussianBlurVars;
struct SequenceModifierData;
struct ColorBalanceModifierData;
struct CurvesModifierData;
struct HueCorrectModifierData;
struct BrightContrastModifierData;
struct SequencerMaskModifierData;
struct SequencerScopes;
struct Effect;
struct BuildEff;
struct PartEff;
struct WaveEff;
struct TreeStoreElem;
struct TreeStore;
struct bProperty;
struct bNearSensor;
struct bMouseSensor;
struct bTouchSensor;
struct bKeyboardSensor;
struct bPropertySensor;
struct bActuatorSensor;
struct bDelaySensor;
struct bCollisionSensor;
struct bRadarSensor;
struct bRandomSensor;
struct bRaySensor;
struct bArmatureSensor;
struct bMessageSensor;
struct bSensor;
struct bJoystickSensor;
struct bExpressionCont;
struct bPythonCont;
struct bController;
struct bAddObjectActuator;
struct bActionActuator;
struct Sound3D;
struct bSoundActuator;
struct bEditObjectActuator;
struct bSceneActuator;
struct bPropertyActuator;
struct bObjectActuator;
struct bIpoActuator;
struct bCameraActuator;
struct bConstraintActuator;
struct bGroupActuator;
struct bRandomActuator;
struct bMessageActuator;
struct bGameActuator;
struct bVisibilityActuator;
struct bTwoDFilterActuator;
struct bParentActuator;
struct bStateActuator;
struct bArmatureActuator;
struct bSteeringActuator;
struct bMouseActuator;
struct bActuator;
struct bSound;
struct GroupObject;
struct Group;
struct Bone;
struct bArmature;
struct bMotionPathVert;
struct bMotionPath;
struct bAnimVizSettings;
struct bPoseChannel;
struct bPose;
struct bIKParam;
struct bItasc;
struct bActionGroup;
struct bAction;
struct bDopeSheet;
struct SpaceAction;
struct bActionChannel;
struct bConstraintChannel;
struct bConstraint;
struct bConstraintTarget;
struct bPythonConstraint;
struct bKinematicConstraint;
struct bSplineIKConstraint;
struct bTrackToConstraint;
struct bRotateLikeConstraint;
struct bLocateLikeConstraint;
struct bSizeLikeConstraint;
struct bSameVolumeConstraint;
struct bTransLikeConstraint;
struct bMinMaxConstraint;
struct bActionConstraint;
struct bLockTrackConstraint;
struct bDampTrackConstraint;
struct bFollowPathConstraint;
struct bStretchToConstraint;
struct bRigidBodyJointConstraint;
struct bClampToConstraint;
struct bChildOfConstraint;
struct bTransformConstraint;
struct bPivotConstraint;
struct bLocLimitConstraint;
struct bRotLimitConstraint;
struct bSizeLimitConstraint;
struct bDistLimitConstraint;
struct bShrinkwrapConstraint;
struct bFollowTrackConstraint;
struct bCameraSolverConstraint;
struct bObjectSolverConstraint;
struct bActionModifier;
struct bActionStrip;
struct bNodeStack;
struct bNodeSocket;
struct bNode;
struct bNodeInstanceKey;
struct bNodeInstanceHashEntry;
struct bNodePreview;
struct bNodeLink;
struct bNodeTree;
struct bNodeSocketValueInt;
struct bNodeSocketValueFloat;
struct bNodeSocketValueBoolean;
struct bNodeSocketValueVector;
struct bNodeSocketValueRGBA;
struct bNodeSocketValueString;
struct NodeFrame;
struct NodeImageAnim;
struct ColorCorrectionData;
struct NodeColorCorrection;
struct NodeBokehImage;
struct NodeBoxMask;
struct NodeEllipseMask;
struct NodeImageLayer;
struct NodeBlurData;
struct NodeDBlurData;
struct NodeBilateralBlurData;
struct NodeHueSat;
struct NodeImageFile;
struct NodeImageMultiFile;
struct NodeImageMultiFileSocket;
struct NodeChroma;
struct NodeTwoXYs;
struct NodeTwoFloats;
struct NodeGeometry;
struct NodeVertexCol;
struct NodeDefocus;
struct NodeScriptDict;
struct NodeGlare;
struct NodeTonemap;
struct NodeLensDist;
struct NodeColorBalance;
struct NodeColorspill;
struct NodeDilateErode;
struct NodeMask;
struct NodeTexBase;
struct NodeTexSky;
struct NodeTexImage;
struct NodeTexChecker;
struct NodeTexBrick;
struct NodeTexEnvironment;
struct NodeTexGradient;
struct NodeTexNoise;
struct NodeTexVoronoi;
struct NodeTexMusgrave;
struct NodeTexWave;
struct NodeTexMagic;
struct NodeShaderAttribute;
struct NodeShaderVectTransform;
struct TexNodeOutput;
struct NodeKeyingScreenData;
struct NodeKeyingData;
struct NodeTrackPosData;
struct NodeTranslateData;
struct NodePlaneTrackDeformData;
struct NodeShaderScript;
struct NodeShaderTangent;
struct NodeShaderNormalMap;
struct NodeShaderUVMap;
struct NodeSunBeams;
struct CurveMapPoint;
struct CurveMap;
struct CurveMapping;
struct Histogram;
struct Scopes;
struct ColorManagedViewSettings;
struct ColorManagedDisplaySettings;
struct ColorManagedColorspaceSettings;
struct BrushClone;
struct Brush;
struct PaletteColor;
struct Palette;
struct PaintCurvePoint;
struct PaintCurve;
struct CustomDataLayer;
struct CustomDataExternal;
struct CustomData;
struct HairKey;
struct ParticleKey;
struct BoidParticle;
struct ParticleSpring;
struct ChildParticle;
struct ParticleTarget;
struct ParticleDupliWeight;
struct ParticleData;
struct SPHFluidSettings;
struct ParticleSettings;
struct ParticleSystem;
struct ClothSimSettings;
struct ClothCollSettings;
struct bGPDspoint;
struct bGPDstroke;
struct bGPDframe;
struct bGPDlayer;
struct bGPdata;
struct ReportList;
struct wmWindowManager;
struct wmWindow;
struct wmKeyMapItem;
struct wmKeyMapDiffItem;
struct wmKeyMap;
struct wmKeyConfig;
struct wmOperator;
struct FModifier;
struct FMod_Generator;
struct FMod_FunctionGenerator;
struct FCM_EnvelopeData;
struct FMod_Envelope;
struct FMod_Cycles;
struct FMod_Python;
struct FMod_Limits;
struct FMod_Noise;
struct FMod_Stepped;
struct DriverTarget;
struct DriverVar;
struct ChannelDriver;
struct FPoint;
struct FCurve;
struct AnimMapPair;
struct AnimMapper;
struct NlaStrip;
struct NlaTrack;
struct KS_Path;
struct KeyingSet;
struct AnimOverride;
struct AnimData;
struct IdAdtTemplate;
struct BoidRule;
struct BoidRuleGoalAvoid;
struct BoidRuleAvoidCollision;
struct BoidRuleFollowLeader;
struct BoidRuleAverageSpeed;
struct BoidRuleFight;
struct BoidData;
struct BoidState;
struct BoidSettings;
struct SmokeDomainSettings;
struct SmokeFlowSettings;
struct SmokeCollSettings;
struct Speaker;
struct MovieClipUser;
struct MovieClipProxy;
struct MovieClip;
struct MovieClipScopes;
struct MovieReconstructedCamera;
struct MovieTrackingCamera;
struct MovieTrackingMarker;
struct MovieTrackingTrack;
struct MovieTrackingPlaneMarker;
struct MovieTrackingPlaneTrack;
struct MovieTrackingSettings;
struct MovieTrackingStabilization;
struct MovieTrackingReconstruction;
struct MovieTrackingObject;
struct MovieTrackingStats;
struct MovieTrackingDopesheetChannel;
struct MovieTrackingDopesheetCoverageSegment;
struct MovieTrackingDopesheet;
struct MovieTracking;
struct DynamicPaintSurface;
struct DynamicPaintCanvasSettings;
struct DynamicPaintBrushSettings;
struct Mask;
struct MaskParent;
struct MaskSplinePointUW;
struct MaskSplinePoint;
struct MaskSpline;
struct MaskLayerShape;
struct MaskLayer;
struct RigidBodyWorld;
struct RigidBodyOb;
struct RigidBodyCon;
struct FreestyleLineSet;
struct FreestyleModuleConfig;
struct FreestyleConfig;
struct LineStyleModifier;
struct LineStyleColorModifier_AlongStroke;
struct LineStyleAlphaModifier_AlongStroke;
struct LineStyleThicknessModifier_AlongStroke;
struct LineStyleColorModifier_DistanceFromCamera;
struct LineStyleAlphaModifier_DistanceFromCamera;
struct LineStyleThicknessModifier_DistanceFromCamera;
struct LineStyleColorModifier_DistanceFromObject;
struct LineStyleAlphaModifier_DistanceFromObject;
struct LineStyleThicknessModifier_DistanceFromObject;
struct LineStyleColorModifier_Material;
struct LineStyleAlphaModifier_Material;
struct LineStyleThicknessModifier_Material;
struct LineStyleGeometryModifier_Sampling;
struct LineStyleGeometryModifier_BezierCurve;
struct LineStyleGeometryModifier_SinusDisplacement;
struct LineStyleGeometryModifier_SpatialNoise;
struct LineStyleGeometryModifier_PerlinNoise1D;
struct LineStyleGeometryModifier_PerlinNoise2D;
struct LineStyleGeometryModifier_BackboneStretcher;
struct LineStyleGeometryModifier_TipRemover;
struct LineStyleGeometryModifier_Polygonalization;
struct LineStyleGeometryModifier_GuidingLines;
struct LineStyleGeometryModifier_Blueprint;
struct LineStyleGeometryModifier_2DOffset;
struct LineStyleGeometryModifier_2DTransform;
struct LineStyleThicknessModifier_Calligraphy;
struct FreestyleLineStyle;

struct Link {
    Link *next /* 8 bytes */;
    Link *prev /* 8 bytes */;
};

struct LinkData {
    LinkData *next /* 8 bytes */;
    LinkData *prev /* 8 bytes */;
    void *data /* 8 bytes */;
};

struct ListBase {
    void *first /* 8 bytes */;
    void *last /* 8 bytes */;
};

struct vec2s {
    short x /* 2 bytes */;
    short y /* 2 bytes */;
};

struct vec2f {
    float x /* 4 bytes */;
    float y /* 4 bytes */;
};

struct vec3f {
    float x /* 4 bytes */;
    float y /* 4 bytes */;
    float z /* 4 bytes */;
};

struct rcti {
    int xmin /* 4 bytes */;
    int xmax /* 4 bytes */;
    int ymin /* 4 bytes */;
    int ymax /* 4 bytes */;
};

struct rctf {
    float xmin /* 4 bytes */;
    float xmax /* 4 bytes */;
    float ymin /* 4 bytes */;
    float ymax /* 4 bytes */;
};

struct IDPropertyData {
    void *pointer /* 8 bytes */;
    ListBase group /* 16 bytes */;
    int val /* 4 bytes */;
    int val2 /* 4 bytes */;
};

struct IDProperty {
    IDProperty *next /* 8 bytes */;
    IDProperty *prev /* 8 bytes */;
    char type /* 1 bytes */;
    char subtype /* 1 bytes */;
    short flag /* 2 bytes */;
    char name[64] /* 64 bytes */;
    int saved /* 4 bytes */;
    IDPropertyData data /* 32 bytes */;
    int len /* 4 bytes */;
    int totallen /* 4 bytes */;
};

struct ID {
    void *next /* 8 bytes */;
    void *prev /* 8 bytes */;
    ID *newid /* 8 bytes */;
    Library *lib /* 8 bytes */;
    char name[66] /* 66 bytes */;
    short flag /* 2 bytes */;
    int us /* 4 bytes */;
    int icon_id /* 4 bytes */;
    int pad2 /* 4 bytes */;
    IDProperty *properties /* 8 bytes */;
};

struct Library {
    ID id /* 120 bytes */;
    ID *idblock /* 8 bytes */;
    void *filedata /* 8 bytes */;
    char name[1024] /* 1024 bytes */;
    char filepath[1024] /* 1024 bytes */;
    Library *parent /* 8 bytes */;
    PackedFile *packedfile /* 8 bytes */;
};

struct PreviewImage {
    int w[2] /* 8 bytes */;
    int h[2] /* 8 bytes */;
    short changed[2] /* 4 bytes */;
    short changed_timestamp[2] /* 4 bytes */;
    int *rect[2] /* 16 bytes */;
    void *gputexture[2] /* 16 bytes */;
};

struct IpoDriver {
    Object *ob /* 8 bytes */;
    short blocktype /* 2 bytes */;
    short adrcode /* 2 bytes */;
    short type /* 2 bytes */;
    short flag /* 2 bytes */;
    char name[128] /* 128 bytes */;
};

struct IpoCurve {
    IpoCurve *next /* 8 bytes */;
    IpoCurve *prev /* 8 bytes */;
    BPoint *bp /* 8 bytes */;
    BezTriple *bezt /* 8 bytes */;
    rctf maxrct /* 16 bytes */;
    rctf totrct /* 16 bytes */;
    short blocktype /* 2 bytes */;
    short adrcode /* 2 bytes */;
    short vartype /* 2 bytes */;
    short totvert /* 2 bytes */;
    short ipo /* 2 bytes */;
    short extrap /* 2 bytes */;
    short flag /* 2 bytes */;
    short rt /* 2 bytes */;
    float ymin /* 4 bytes */;
    float ymax /* 4 bytes */;
    int bitmask /* 4 bytes */;
    float slide_min /* 4 bytes */;
    float slide_max /* 4 bytes */;
    float curval /* 4 bytes */;
    IpoDriver *driver /* 8 bytes */;
};

struct Ipo {
    ID id /* 120 bytes */;
    ListBase curve /* 16 bytes */;
    rctf cur /* 16 bytes */;
    short blocktype /* 2 bytes */;
    short showkey /* 2 bytes */;
    short muteipo /* 2 bytes */;
    short pad /* 2 bytes */;
};

struct KeyBlock {
    KeyBlock *next /* 8 bytes */;
    KeyBlock *prev /* 8 bytes */;
    float pos /* 4 bytes */;
    float curval /* 4 bytes */;
    short type /* 2 bytes */;
    short pad1 /* 2 bytes */;
    short relative /* 2 bytes */;
    short flag /* 2 bytes */;
    int totelem /* 4 bytes */;
    int uid /* 4 bytes */;
    void *data /* 8 bytes */;
    char name[64] /* 64 bytes */;
    char vgroup[64] /* 64 bytes */;
    float slidermin /* 4 bytes */;
    float slidermax /* 4 bytes */;
};

struct Key {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
    KeyBlock *refkey /* 8 bytes */;
    char elemstr[32] /* 32 bytes */;
    int elemsize /* 4 bytes */;
    int pad /* 4 bytes */;
    ListBase block /* 16 bytes */;
    Ipo *ipo /* 8 bytes */;
    ID *from /* 8 bytes */;
    int totkey /* 4 bytes */;
    short flag /* 2 bytes */;
    char type /* 1 bytes */;
    char pad2 /* 1 bytes */;
    float ctime /* 4 bytes */;
    int uidgen /* 4 bytes */;
};

struct TextLine {
    TextLine *next /* 8 bytes */;
    TextLine *prev /* 8 bytes */;
    char *line /* 8 bytes */;
    char *format /* 8 bytes */;
    int len /* 4 bytes */;
    int blen /* 4 bytes */;
};

struct Text {
    ID id /* 120 bytes */;
    char *name /* 8 bytes */;
    int flags /* 4 bytes */;
    int nlines /* 4 bytes */;
    ListBase lines /* 16 bytes */;
    TextLine *curl /* 8 bytes */;
    TextLine *sell /* 8 bytes */;
    int curc /* 4 bytes */;
    int selc /* 4 bytes */;
    char *undo_buf /* 8 bytes */;
    int undo_pos /* 4 bytes */;
    int undo_len /* 4 bytes */;
    void *compiled /* 8 bytes */;
    double mtime /* 8 bytes */;
};

struct PackedFile {
    int size /* 4 bytes */;
    int seek /* 4 bytes */;
    void *data /* 8 bytes */;
};

struct GPUDOFSettings {
    float focus_distance /* 4 bytes */;
    float fstop /* 4 bytes */;
    float focal_length /* 4 bytes */;
    float sensor /* 4 bytes */;
};

struct GPUSSAOSettings {
    float factor /* 4 bytes */;
    float color[3] /* 12 bytes */;
    float distance_max /* 4 bytes */;
    float attenuation /* 4 bytes */;
    int samples /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct GPUFXSettings {
    GPUDOFSettings *dof /* 8 bytes */;
    GPUSSAOSettings *ssao /* 8 bytes */;
    char fx_flag /* 1 bytes */;
    char pad[7] /* 7 bytes */;
};

struct Camera {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
    char type /* 1 bytes */;
    char dtx /* 1 bytes */;
    short flag /* 2 bytes */;
    float passepartalpha /* 4 bytes */;
    float clipsta /* 4 bytes */;
    float clipend /* 4 bytes */;
    float lens /* 4 bytes */;
    float ortho_scale /* 4 bytes */;
    float drawsize /* 4 bytes */;
    float sensor_x /* 4 bytes */;
    float sensor_y /* 4 bytes */;
    float shiftx /* 4 bytes */;
    float shifty /* 4 bytes */;
    float YF_dofdist /* 4 bytes */;
    Ipo *ipo /* 8 bytes */;
    Object *dof_ob /* 8 bytes */;
    GPUDOFSettings gpu_dof /* 16 bytes */;
    char sensor_fit /* 1 bytes */;
    char pad[7] /* 7 bytes */;
};

struct ImageUser {
    Scene *scene /* 8 bytes */;
    int framenr /* 4 bytes */;
    int frames /* 4 bytes */;
    int offset /* 4 bytes */;
    int sfra /* 4 bytes */;
    char fie_ima /* 1 bytes */;
    char cycl /* 1 bytes */;
    char ok /* 1 bytes */;
    char pad /* 1 bytes */;
    short multi_index /* 2 bytes */;
    short layer /* 2 bytes */;
    short pass /* 2 bytes */;
    short flag /* 2 bytes */;
    int pad2 /* 4 bytes */;
};

struct RenderSlot {
    char name[64] /* 64 bytes */;
};

struct ColorManagedColorspaceSettings {
    char name[64] /* 64 bytes */;
};

struct Image {
    ID id /* 120 bytes */;
    char name[1024] /* 1024 bytes */;
    void *cache /* 8 bytes */;
    void *gputexture /* 8 bytes */;
    void *anim /* 8 bytes */;
    void *rr /* 8 bytes */;
    void *renders[8] /* 64 bytes */;
    short render_slot /* 2 bytes */;
    short last_render_slot /* 2 bytes */;
    short ok /* 2 bytes */;
    short flag /* 2 bytes */;
    short source /* 2 bytes */;
    short type /* 2 bytes */;
    int lastframe /* 4 bytes */;
    short tpageflag /* 2 bytes */;
    short totbind /* 2 bytes */;
    short xrep /* 2 bytes */;
    short yrep /* 2 bytes */;
    short twsta /* 2 bytes */;
    short twend /* 2 bytes */;
    int bindcode /* 4 bytes */;
    int *repbind /* 8 bytes */;
    PackedFile *packedfile /* 8 bytes */;
    PreviewImage *preview /* 8 bytes */;
    float lastupdate /* 4 bytes */;
    int lastused /* 4 bytes */;
    short animspeed /* 2 bytes */;
    short pad2 /* 2 bytes */;
    int gen_x /* 4 bytes */;
    int gen_y /* 4 bytes */;
    char gen_type /* 1 bytes */;
    char gen_flag /* 1 bytes */;
    short gen_depth /* 2 bytes */;
    float gen_color[4] /* 16 bytes */;
    float aspx /* 4 bytes */;
    float aspy /* 4 bytes */;
    ColorManagedColorspaceSettings colorspace_settings /* 64 bytes */;
    char alpha_mode /* 1 bytes */;
    char pad[7] /* 7 bytes */;
    RenderSlot render_slots[8] /* 512 bytes */;
};

struct MTex {
    short texco /* 2 bytes */;
    short mapto /* 2 bytes */;
    short maptoneg /* 2 bytes */;
    short blendtype /* 2 bytes */;
    Object *object /* 8 bytes */;
    Tex *tex /* 8 bytes */;
    char uvname[64] /* 64 bytes */;
    char projx /* 1 bytes */;
    char projy /* 1 bytes */;
    char projz /* 1 bytes */;
    char mapping /* 1 bytes */;
    char brush_map_mode /* 1 bytes */;
    char brush_angle_mode /* 1 bytes */;
    char pad[2] /* 2 bytes */;
    float ofs[3] /* 12 bytes */;
    float size[3] /* 12 bytes */;
    float rot /* 4 bytes */;
    float random_angle /* 4 bytes */;
    short texflag /* 2 bytes */;
    short colormodel /* 2 bytes */;
    short pmapto /* 2 bytes */;
    short pmaptoneg /* 2 bytes */;
    short normapspace /* 2 bytes */;
    short which_output /* 2 bytes */;
    float r /* 4 bytes */;
    float g /* 4 bytes */;
    float b /* 4 bytes */;
    float k /* 4 bytes */;
    float def_var /* 4 bytes */;
    float rt /* 4 bytes */;
    float colfac /* 4 bytes */;
    float varfac /* 4 bytes */;
    float norfac /* 4 bytes */;
    float dispfac /* 4 bytes */;
    float warpfac /* 4 bytes */;
    float colspecfac /* 4 bytes */;
    float mirrfac /* 4 bytes */;
    float alphafac /* 4 bytes */;
    float difffac /* 4 bytes */;
    float specfac /* 4 bytes */;
    float emitfac /* 4 bytes */;
    float hardfac /* 4 bytes */;
    float raymirrfac /* 4 bytes */;
    float translfac /* 4 bytes */;
    float ambfac /* 4 bytes */;
    float colemitfac /* 4 bytes */;
    float colreflfac /* 4 bytes */;
    float coltransfac /* 4 bytes */;
    float densfac /* 4 bytes */;
    float scatterfac /* 4 bytes */;
    float reflfac /* 4 bytes */;
    float timefac /* 4 bytes */;
    float lengthfac /* 4 bytes */;
    float clumpfac /* 4 bytes */;
    float dampfac /* 4 bytes */;
    float kinkfac /* 4 bytes */;
    float kinkampfac /* 4 bytes */;
    float roughfac /* 4 bytes */;
    float padensfac /* 4 bytes */;
    float gravityfac /* 4 bytes */;
    float lifefac /* 4 bytes */;
    float sizefac /* 4 bytes */;
    float ivelfac /* 4 bytes */;
    float fieldfac /* 4 bytes */;
    int pad2 /* 4 bytes */;
    float shadowfac /* 4 bytes */;
    float zenupfac /* 4 bytes */;
    float zendownfac /* 4 bytes */;
    float blendfac /* 4 bytes */;
};

struct CBData {
    float r /* 4 bytes */;
    float g /* 4 bytes */;
    float b /* 4 bytes */;
    float a /* 4 bytes */;
    float pos /* 4 bytes */;
    int cur /* 4 bytes */;
};

struct ColorBand {
    short tot /* 2 bytes */;
    short cur /* 2 bytes */;
    char ipotype /* 1 bytes */;
    char ipotype_hue /* 1 bytes */;
    char color_mode /* 1 bytes */;
    char pad[1] /* 1 bytes */;
    CBData data[32] /* 768 bytes */;
};

struct EnvMap {
    Object *object /* 8 bytes */;
    Image *ima /* 8 bytes */;
    void *cube[6] /* 48 bytes */;
    float imat[4][4] /* 64 bytes */;
    float obimat[3][3] /* 36 bytes */;
    short type /* 2 bytes */;
    short stype /* 2 bytes */;
    float clipsta /* 4 bytes */;
    float clipend /* 4 bytes */;
    float viewscale /* 4 bytes */;
    int notlay /* 4 bytes */;
    short cuberes /* 2 bytes */;
    short depth /* 2 bytes */;
    int ok /* 4 bytes */;
    int lastframe /* 4 bytes */;
    short recalc /* 2 bytes */;
    short lastsize /* 2 bytes */;
};

struct PointDensity {
    short flag /* 2 bytes */;
    short falloff_type /* 2 bytes */;
    float falloff_softness /* 4 bytes */;
    float radius /* 4 bytes */;
    short source /* 2 bytes */;
    short color_source /* 2 bytes */;
    int totpoints /* 4 bytes */;
    int pdpad /* 4 bytes */;
    Object *object /* 8 bytes */;
    int psys /* 4 bytes */;
    short psys_cache_space /* 2 bytes */;
    short ob_cache_space /* 2 bytes */;
    void *point_tree /* 8 bytes */;
    float *point_data /* 8 bytes */;
    float noise_size /* 4 bytes */;
    short noise_depth /* 2 bytes */;
    short noise_influence /* 2 bytes */;
    short noise_basis /* 2 bytes */;
    short pdpad3[3] /* 6 bytes */;
    float noise_fac /* 4 bytes */;
    float speed_scale /* 4 bytes */;
    float falloff_speed_scale /* 4 bytes */;
    float pdpad2 /* 4 bytes */;
    ColorBand *coba /* 8 bytes */;
    CurveMapping *falloff_curve /* 8 bytes */;
};

struct VoxelData {
    int resol[3] /* 12 bytes */;
    int interp_type /* 4 bytes */;
    short file_format /* 2 bytes */;
    short flag /* 2 bytes */;
    short extend /* 2 bytes */;
    short smoked_type /* 2 bytes */;
    short hair_type /* 2 bytes */;
    short data_type /* 2 bytes */;
    int _pad /* 4 bytes */;
    Object *object /* 8 bytes */;
    float int_multiplier /* 4 bytes */;
    int still_frame /* 4 bytes */;
    char source_path[1024] /* 1024 bytes */;
    float *dataset /* 8 bytes */;
    int cachedframe /* 4 bytes */;
    int ok /* 4 bytes */;
};

struct OceanTex {
    Object *object /* 8 bytes */;
    char oceanmod[64] /* 64 bytes */;
    int output /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct Tex {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
    float noisesize /* 4 bytes */;
    float turbul /* 4 bytes */;
    float bright /* 4 bytes */;
    float contrast /* 4 bytes */;
    float saturation /* 4 bytes */;
    float rfac /* 4 bytes */;
    float gfac /* 4 bytes */;
    float bfac /* 4 bytes */;
    float filtersize /* 4 bytes */;
    float pad2 /* 4 bytes */;
    float mg_H /* 4 bytes */;
    float mg_lacunarity /* 4 bytes */;
    float mg_octaves /* 4 bytes */;
    float mg_offset /* 4 bytes */;
    float mg_gain /* 4 bytes */;
    float dist_amount /* 4 bytes */;
    float ns_outscale /* 4 bytes */;
    float vn_w1 /* 4 bytes */;
    float vn_w2 /* 4 bytes */;
    float vn_w3 /* 4 bytes */;
    float vn_w4 /* 4 bytes */;
    float vn_mexp /* 4 bytes */;
    short vn_distm /* 2 bytes */;
    short vn_coltype /* 2 bytes */;
    short noisedepth /* 2 bytes */;
    short noisetype /* 2 bytes */;
    short noisebasis /* 2 bytes */;
    short noisebasis2 /* 2 bytes */;
    short imaflag /* 2 bytes */;
    short flag /* 2 bytes */;
    short type /* 2 bytes */;
    short stype /* 2 bytes */;
    float cropxmin /* 4 bytes */;
    float cropymin /* 4 bytes */;
    float cropxmax /* 4 bytes */;
    float cropymax /* 4 bytes */;
    int texfilter /* 4 bytes */;
    int afmax /* 4 bytes */;
    short xrepeat /* 2 bytes */;
    short yrepeat /* 2 bytes */;
    short extend /* 2 bytes */;
    short fie_ima /* 2 bytes */;
    int len /* 4 bytes */;
    int frames /* 4 bytes */;
    int offset /* 4 bytes */;
    int sfra /* 4 bytes */;
    float checkerdist /* 4 bytes */;
    float nabla /* 4 bytes */;
    float pad1 /* 4 bytes */;
    ImageUser iuser /* 40 bytes */;
    bNodeTree *nodetree /* 8 bytes */;
    Ipo *ipo /* 8 bytes */;
    Image *ima /* 8 bytes */;
    ColorBand *coba /* 8 bytes */;
    EnvMap *env /* 8 bytes */;
    PreviewImage *preview /* 8 bytes */;
    PointDensity *pd /* 8 bytes */;
    VoxelData *vd /* 8 bytes */;
    OceanTex *ot /* 8 bytes */;
    char use_nodes /* 1 bytes */;
    char pad[7] /* 7 bytes */;
};

struct TexMapping {
    float loc[3] /* 12 bytes */;
    float rot[3] /* 12 bytes */;
    float size[3] /* 12 bytes */;
    int flag /* 4 bytes */;
    char projx /* 1 bytes */;
    char projy /* 1 bytes */;
    char projz /* 1 bytes */;
    char mapping /* 1 bytes */;
    int type /* 4 bytes */;
    float mat[4][4] /* 64 bytes */;
    float min[3] /* 12 bytes */;
    float max[3] /* 12 bytes */;
    Object *ob /* 8 bytes */;
};

struct ColorMapping {
    ColorBand coba /* 776 bytes */;
    float bright /* 4 bytes */;
    float contrast /* 4 bytes */;
    float saturation /* 4 bytes */;
    int flag /* 4 bytes */;
    float blend_color[3] /* 12 bytes */;
    float blend_factor /* 4 bytes */;
    int blend_type /* 4 bytes */;
    int pad[3] /* 12 bytes */;
};

struct Lamp {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
    short type /* 2 bytes */;
    short flag /* 2 bytes */;
    int mode /* 4 bytes */;
    short colormodel /* 2 bytes */;
    short totex /* 2 bytes */;
    float r /* 4 bytes */;
    float g /* 4 bytes */;
    float b /* 4 bytes */;
    float k /* 4 bytes */;
    float shdwr /* 4 bytes */;
    float shdwg /* 4 bytes */;
    float shdwb /* 4 bytes */;
    float shdwpad /* 4 bytes */;
    float energy /* 4 bytes */;
    float dist /* 4 bytes */;
    float spotsize /* 4 bytes */;
    float spotblend /* 4 bytes */;
    float haint /* 4 bytes */;
    float att1 /* 4 bytes */;
    float att2 /* 4 bytes */;
    CurveMapping *curfalloff /* 8 bytes */;
    short falloff_type /* 2 bytes */;
    short pad2 /* 2 bytes */;
    float clipsta /* 4 bytes */;
    float clipend /* 4 bytes */;
    float bias /* 4 bytes */;
    float soft /* 4 bytes */;
    float compressthresh /* 4 bytes */;
    float bleedbias /* 4 bytes */;
    float pad5 /* 4 bytes */;
    short bufsize /* 2 bytes */;
    short samp /* 2 bytes */;
    short buffers /* 2 bytes */;
    short filtertype /* 2 bytes */;
    char bufflag /* 1 bytes */;
    char buftype /* 1 bytes */;
    short ray_samp /* 2 bytes */;
    short ray_sampy /* 2 bytes */;
    short ray_sampz /* 2 bytes */;
    short ray_samp_type /* 2 bytes */;
    short area_shape /* 2 bytes */;
    float area_size /* 4 bytes */;
    float area_sizey /* 4 bytes */;
    float area_sizez /* 4 bytes */;
    float adapt_thresh /* 4 bytes */;
    short ray_samp_method /* 2 bytes */;
    short shadowmap_type /* 2 bytes */;
    short texact /* 2 bytes */;
    short shadhalostep /* 2 bytes */;
    short sun_effect_type /* 2 bytes */;
    short skyblendtype /* 2 bytes */;
    float horizon_brightness /* 4 bytes */;
    float spread /* 4 bytes */;
    float sun_brightness /* 4 bytes */;
    float sun_size /* 4 bytes */;
    float backscattered_light /* 4 bytes */;
    float sun_intensity /* 4 bytes */;
    float atm_turbidity /* 4 bytes */;
    float atm_inscattering_factor /* 4 bytes */;
    float atm_extinction_factor /* 4 bytes */;
    float atm_distance_factor /* 4 bytes */;
    float skyblendfac /* 4 bytes */;
    float sky_exposure /* 4 bytes */;
    float shadow_frustum_size /* 4 bytes */;
    short sky_colorspace /* 2 bytes */;
    char pad4[2] /* 2 bytes */;
    Ipo *ipo /* 8 bytes */;
    MTex *mtex[18] /* 144 bytes */;
    short pr_texture /* 2 bytes */;
    short use_nodes /* 2 bytes */;
    char pad6[4] /* 4 bytes */;
    PreviewImage *preview /* 8 bytes */;
    bNodeTree *nodetree /* 8 bytes */;
};

struct VolumeSettings {
    float density /* 4 bytes */;
    float emission /* 4 bytes */;
    float scattering /* 4 bytes */;
    float reflection /* 4 bytes */;
    float emission_col[3] /* 12 bytes */;
    float transmission_col[3] /* 12 bytes */;
    float reflection_col[3] /* 12 bytes */;
    float density_scale /* 4 bytes */;
    float depth_cutoff /* 4 bytes */;
    float asymmetry /* 4 bytes */;
    short stepsize_type /* 2 bytes */;
    short shadeflag /* 2 bytes */;
    short shade_type /* 2 bytes */;
    short precache_resolution /* 2 bytes */;
    float stepsize /* 4 bytes */;
    float ms_diff /* 4 bytes */;
    float ms_intensity /* 4 bytes */;
    float ms_spread /* 4 bytes */;
};

struct GameSettings {
    int flag /* 4 bytes */;
    int alpha_blend /* 4 bytes */;
    int face_orientation /* 4 bytes */;
    int pad1 /* 4 bytes */;
};

struct TexPaintSlot {
    Image *ima /* 8 bytes */;
    char *uvname /* 8 bytes */;
    int index /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct Material {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
    short material_type /* 2 bytes */;
    short flag /* 2 bytes */;
    float r /* 4 bytes */;
    float g /* 4 bytes */;
    float b /* 4 bytes */;
    float specr /* 4 bytes */;
    float specg /* 4 bytes */;
    float specb /* 4 bytes */;
    float mirr /* 4 bytes */;
    float mirg /* 4 bytes */;
    float mirb /* 4 bytes */;
    float ambr /* 4 bytes */;
    float ambb /* 4 bytes */;
    float ambg /* 4 bytes */;
    float amb /* 4 bytes */;
    float emitt /* 4 bytes */;
    float ang /* 4 bytes */;
    float spectra /* 4 bytes */;
    float ray_mirror /* 4 bytes */;
    float alpha /* 4 bytes */;
    float ref /* 4 bytes */;
    float spec /* 4 bytes */;
    float zoffs /* 4 bytes */;
    float add /* 4 bytes */;
    float translucency /* 4 bytes */;
    VolumeSettings vol /* 88 bytes */;
    GameSettings game /* 16 bytes */;
    float fresnel_mir /* 4 bytes */;
    float fresnel_mir_i /* 4 bytes */;
    float fresnel_tra /* 4 bytes */;
    float fresnel_tra_i /* 4 bytes */;
    float filter /* 4 bytes */;
    float tx_limit /* 4 bytes */;
    float tx_falloff /* 4 bytes */;
    short ray_depth /* 2 bytes */;
    short ray_depth_tra /* 2 bytes */;
    short har /* 2 bytes */;
    char seed1 /* 1 bytes */;
    char seed2 /* 1 bytes */;
    float gloss_mir /* 4 bytes */;
    float gloss_tra /* 4 bytes */;
    short samp_gloss_mir /* 2 bytes */;
    short samp_gloss_tra /* 2 bytes */;
    float adapt_thresh_mir /* 4 bytes */;
    float adapt_thresh_tra /* 4 bytes */;
    float aniso_gloss_mir /* 4 bytes */;
    float dist_mir /* 4 bytes */;
    short fadeto_mir /* 2 bytes */;
    short shade_flag /* 2 bytes */;
    int mode /* 4 bytes */;
    int mode_l /* 4 bytes */;
    int mode2 /* 4 bytes */;
    int mode2_l /* 4 bytes */;
    short flarec /* 2 bytes */;
    short starc /* 2 bytes */;
    short linec /* 2 bytes */;
    short ringc /* 2 bytes */;
    float hasize /* 4 bytes */;
    float flaresize /* 4 bytes */;
    float subsize /* 4 bytes */;
    float flareboost /* 4 bytes */;
    float strand_sta /* 4 bytes */;
    float strand_end /* 4 bytes */;
    float strand_ease /* 4 bytes */;
    float strand_surfnor /* 4 bytes */;
    float strand_min /* 4 bytes */;
    float strand_widthfade /* 4 bytes */;
    char strand_uvname[64] /* 64 bytes */;
    float sbias /* 4 bytes */;
    float lbias /* 4 bytes */;
    float shad_alpha /* 4 bytes */;
    int septex /* 4 bytes */;
    char rgbsel /* 1 bytes */;
    char texact /* 1 bytes */;
    char pr_type /* 1 bytes */;
    char use_nodes /* 1 bytes */;
    short pr_lamp /* 2 bytes */;
    short pr_texture /* 2 bytes */;
    short ml_flag /* 2 bytes */;
    char mapflag /* 1 bytes */;
    char pad /* 1 bytes */;
    short diff_shader /* 2 bytes */;
    short spec_shader /* 2 bytes */;
    float roughness /* 4 bytes */;
    float refrac /* 4 bytes */;
    float param[4] /* 16 bytes */;
    float rms /* 4 bytes */;
    float darkness /* 4 bytes */;
    short texco /* 2 bytes */;
    short mapto /* 2 bytes */;
    ColorBand *ramp_col /* 8 bytes */;
    ColorBand *ramp_spec /* 8 bytes */;
    char rampin_col /* 1 bytes */;
    char rampin_spec /* 1 bytes */;
    char rampblend_col /* 1 bytes */;
    char rampblend_spec /* 1 bytes */;
    short ramp_show /* 2 bytes */;
    short pad3 /* 2 bytes */;
    float rampfac_col /* 4 bytes */;
    float rampfac_spec /* 4 bytes */;
    MTex *mtex[18] /* 144 bytes */;
    bNodeTree *nodetree /* 8 bytes */;
    Ipo *ipo /* 8 bytes */;
    Group *group /* 8 bytes */;
    PreviewImage *preview /* 8 bytes */;
    float friction /* 4 bytes */;
    float fh /* 4 bytes */;
    float reflect /* 4 bytes */;
    float fhdist /* 4 bytes */;
    float xyfrict /* 4 bytes */;
    short dynamode /* 2 bytes */;
    short pad2 /* 2 bytes */;
    float sss_radius[3] /* 12 bytes */;
    float sss_col[3] /* 12 bytes */;
    float sss_error /* 4 bytes */;
    float sss_scale /* 4 bytes */;
    float sss_ior /* 4 bytes */;
    float sss_colfac /* 4 bytes */;
    float sss_texfac /* 4 bytes */;
    float sss_front /* 4 bytes */;
    float sss_back /* 4 bytes */;
    short sss_flag /* 2 bytes */;
    short sss_preset /* 2 bytes */;
    int mapto_textured /* 4 bytes */;
    short shadowonly_flag /* 2 bytes */;
    short index /* 2 bytes */;
    float line_col[4] /* 16 bytes */;
    short line_priority /* 2 bytes */;
    short vcol_alpha /* 2 bytes */;
    short paint_active_slot /* 2 bytes */;
    short paint_clone_slot /* 2 bytes */;
    short tot_slots /* 2 bytes */;
    short pad4[3] /* 6 bytes */;
    TexPaintSlot *texpaintslot /* 8 bytes */;
    ListBase gpumaterial /* 16 bytes */;
};

struct VFont {
    ID id /* 120 bytes */;
    char name[1024] /* 1024 bytes */;
    void *data /* 8 bytes */;
    PackedFile *packedfile /* 8 bytes */;
    PackedFile *temp_pf /* 8 bytes */;
};

struct MetaElem {
    MetaElem *next /* 8 bytes */;
    MetaElem *prev /* 8 bytes */;
    BoundBox *bb /* 8 bytes */;
    short type /* 2 bytes */;
    short flag /* 2 bytes */;
    short selcol1 /* 2 bytes */;
    short selcol2 /* 2 bytes */;
    float x /* 4 bytes */;
    float y /* 4 bytes */;
    float z /* 4 bytes */;
    float quat[4] /* 16 bytes */;
    float expx /* 4 bytes */;
    float expy /* 4 bytes */;
    float expz /* 4 bytes */;
    float rad /* 4 bytes */;
    float rad2 /* 4 bytes */;
    float s /* 4 bytes */;
    float len /* 4 bytes */;
    float *mat /* 8 bytes */;
    float *imat /* 8 bytes */;
};

struct MetaBall {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
    ListBase elems /* 16 bytes */;
    ListBase disp /* 16 bytes */;
    ListBase *editelems /* 8 bytes */;
    Ipo *ipo /* 8 bytes */;
    Material **mat /* 8 bytes */;
    char flag /* 1 bytes */;
    char flag2 /* 1 bytes */;
    short totcol /* 2 bytes */;
    short texflag /* 2 bytes */;
    short pad /* 2 bytes */;
    float loc[3] /* 12 bytes */;
    float size[3] /* 12 bytes */;
    float rot[3] /* 12 bytes */;
    float wiresize /* 4 bytes */;
    float rendersize /* 4 bytes */;
    float thresh /* 4 bytes */;
    MetaElem *lastelem /* 8 bytes */;
};

struct BezTriple {
    float vec[3][3] /* 36 bytes */;
    float alfa /* 4 bytes */;
    float weight /* 4 bytes */;
    float radius /* 4 bytes */;
    char ipo /* 1 bytes */;
    char h1 /* 1 bytes */;
    char h2 /* 1 bytes */;
    char f1 /* 1 bytes */;
    char f2 /* 1 bytes */;
    char f3 /* 1 bytes */;
    char hide /* 1 bytes */;
    char easing /* 1 bytes */;
    float back /* 4 bytes */;
    float amplitude /* 4 bytes */;
    float period /* 4 bytes */;
    char pad[4] /* 4 bytes */;
};

struct BPoint {
    float vec[4] /* 16 bytes */;
    float alfa /* 4 bytes */;
    float weight /* 4 bytes */;
    short f1 /* 2 bytes */;
    short hide /* 2 bytes */;
    float radius /* 4 bytes */;
    float pad /* 4 bytes */;
};

struct Nurb {
    Nurb *next /* 8 bytes */;
    Nurb *prev /* 8 bytes */;
    short type /* 2 bytes */;
    short mat_nr /* 2 bytes */;
    short hide /* 2 bytes */;
    short flag /* 2 bytes */;
    int pntsu /* 4 bytes */;
    int pntsv /* 4 bytes */;
    short pad[2] /* 4 bytes */;
    short resolu /* 2 bytes */;
    short resolv /* 2 bytes */;
    short orderu /* 2 bytes */;
    short orderv /* 2 bytes */;
    short flagu /* 2 bytes */;
    short flagv /* 2 bytes */;
    float *knotsu /* 8 bytes */;
    float *knotsv /* 8 bytes */;
    BPoint *bp /* 8 bytes */;
    BezTriple *bezt /* 8 bytes */;
    short tilt_interp /* 2 bytes */;
    short radius_interp /* 2 bytes */;
    int charidx /* 4 bytes */;
};

struct CharInfo {
    short kern /* 2 bytes */;
    short mat_nr /* 2 bytes */;
    char flag /* 1 bytes */;
    char pad /* 1 bytes */;
    short pad2 /* 2 bytes */;
};

struct TextBox {
    float x /* 4 bytes */;
    float y /* 4 bytes */;
    float w /* 4 bytes */;
    float h /* 4 bytes */;
};

struct EditNurb {
    ListBase nurbs /* 16 bytes */;
    void *keyindex /* 8 bytes */;
    int shapenr /* 4 bytes */;
    char pad[4] /* 4 bytes */;
};

struct Curve {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
    BoundBox *bb /* 8 bytes */;
    ListBase nurb /* 16 bytes */;
    EditNurb *editnurb /* 8 bytes */;
    Object *bevobj /* 8 bytes */;
    Object *taperobj /* 8 bytes */;
    Object *textoncurve /* 8 bytes */;
    Ipo *ipo /* 8 bytes */;
    Key *key /* 8 bytes */;
    Material **mat /* 8 bytes */;
    float loc[3] /* 12 bytes */;
    float size[3] /* 12 bytes */;
    float rot[3] /* 12 bytes */;
    short type /* 2 bytes */;
    short texflag /* 2 bytes */;
    short drawflag /* 2 bytes */;
    short twist_mode /* 2 bytes */;
    float twist_smooth /* 4 bytes */;
    float smallcaps_scale /* 4 bytes */;
    int pathlen /* 4 bytes */;
    short bevresol /* 2 bytes */;
    short totcol /* 2 bytes */;
    int flag /* 4 bytes */;
    float width /* 4 bytes */;
    float ext1 /* 4 bytes */;
    float ext2 /* 4 bytes */;
    short resolu /* 2 bytes */;
    short resolv /* 2 bytes */;
    short resolu_ren /* 2 bytes */;
    short resolv_ren /* 2 bytes */;
    int actnu /* 4 bytes */;
    int actvert /* 4 bytes */;
    char pad[4] /* 4 bytes */;
    short lines /* 2 bytes */;
    char spacemode /* 1 bytes */;
    char pad1 /* 1 bytes */;
    float spacing /* 4 bytes */;
    float linedist /* 4 bytes */;
    float shear /* 4 bytes */;
    float fsize /* 4 bytes */;
    float wordspace /* 4 bytes */;
    float ulpos /* 4 bytes */;
    float ulheight /* 4 bytes */;
    float xof /* 4 bytes */;
    float yof /* 4 bytes */;
    float linewidth /* 4 bytes */;
    int pos /* 4 bytes */;
    int selstart /* 4 bytes */;
    int selend /* 4 bytes */;
    int len_wchar /* 4 bytes */;
    int len /* 4 bytes */;
    char *str /* 8 bytes */;
    void *editfont /* 8 bytes */;
    char family[64] /* 64 bytes */;
    VFont *vfont /* 8 bytes */;
    VFont *vfontb /* 8 bytes */;
    VFont *vfonti /* 8 bytes */;
    VFont *vfontbi /* 8 bytes */;
    TextBox *tb /* 8 bytes */;
    int totbox /* 4 bytes */;
    int actbox /* 4 bytes */;
    CharInfo *strinfo /* 8 bytes */;
    CharInfo curinfo /* 8 bytes */;
    float ctime /* 4 bytes */;
    float bevfac1 /* 4 bytes */;
    float bevfac2 /* 4 bytes */;
    char bevfac1_mapping /* 1 bytes */;
    char bevfac2_mapping /* 1 bytes */;
    char pad2[2] /* 2 bytes */;
};

struct CustomDataLayer {
    int type /* 4 bytes */;
    int offset /* 4 bytes */;
    int flag /* 4 bytes */;
    int active /* 4 bytes */;
    int active_rnd /* 4 bytes */;
    int active_clone /* 4 bytes */;
    int active_mask /* 4 bytes */;
    int uid /* 4 bytes */;
    char name[64] /* 64 bytes */;
    void *data /* 8 bytes */;
};

struct CustomDataExternal {
    char filename[1024] /* 1024 bytes */;
};

struct CustomData {
    CustomDataLayer *layers /* 8 bytes */;
    int typemap[42] /* 168 bytes */;
    int pad_i1 /* 4 bytes */;
    int totlayer /* 4 bytes */;
    int maxlayer /* 4 bytes */;
    int totsize /* 4 bytes */;
    void *pool /* 8 bytes */;
    CustomDataExternal *external /* 8 bytes */;
};

struct Mesh {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
    BoundBox *bb /* 8 bytes */;
    Ipo *ipo /* 8 bytes */;
    Key *key /* 8 bytes */;
    Material **mat /* 8 bytes */;
    MSelect *mselect /* 8 bytes */;
    MPoly *mpoly /* 8 bytes */;
    MTexPoly *mtpoly /* 8 bytes */;
    MLoop *mloop /* 8 bytes */;
    MLoopUV *mloopuv /* 8 bytes */;
    MLoopCol *mloopcol /* 8 bytes */;
    MFace *mface /* 8 bytes */;
    MTFace *mtface /* 8 bytes */;
    TFace *tface /* 8 bytes */;
    MVert *mvert /* 8 bytes */;
    MEdge *medge /* 8 bytes */;
    MDeformVert *dvert /* 8 bytes */;
    MCol *mcol /* 8 bytes */;
    Mesh *texcomesh /* 8 bytes */;
    void *edit_btmesh /* 8 bytes */;
    CustomData vdata /* 208 bytes */;
    CustomData edata /* 208 bytes */;
    CustomData fdata /* 208 bytes */;
    CustomData pdata /* 208 bytes */;
    CustomData ldata /* 208 bytes */;
    int totvert /* 4 bytes */;
    int totedge /* 4 bytes */;
    int totface /* 4 bytes */;
    int totselect /* 4 bytes */;
    int totpoly /* 4 bytes */;
    int totloop /* 4 bytes */;
    int act_face /* 4 bytes */;
    float loc[3] /* 12 bytes */;
    float size[3] /* 12 bytes */;
    float rot[3] /* 12 bytes */;
    int drawflag /* 4 bytes */;
    short texflag /* 2 bytes */;
    short flag /* 2 bytes */;
    float smoothresh /* 4 bytes */;
    int pad2 /* 4 bytes */;
    char cd_flag /* 1 bytes */;
    char pad /* 1 bytes */;
    char subdiv /* 1 bytes */;
    char subdivr /* 1 bytes */;
    char subsurftype /* 1 bytes */;
    char editflag /* 1 bytes */;
    short totcol /* 2 bytes */;
    Multires *mr /* 8 bytes */;
};

struct TFace {
    void *tpage /* 8 bytes */;
    float uv[4][2] /* 32 bytes */;
    int col[4] /* 16 bytes */;
    char flag /* 1 bytes */;
    char transp /* 1 bytes */;
    short mode /* 2 bytes */;
    short tile /* 2 bytes */;
    short unwrap /* 2 bytes */;
};

struct MFace {
    int v1 /* 4 bytes */;
    int v2 /* 4 bytes */;
    int v3 /* 4 bytes */;
    int v4 /* 4 bytes */;
    short mat_nr /* 2 bytes */;
    char edcode /* 1 bytes */;
    char flag /* 1 bytes */;
};

struct MEdge {
    int v1 /* 4 bytes */;
    int v2 /* 4 bytes */;
    char crease /* 1 bytes */;
    char bweight /* 1 bytes */;
    short flag /* 2 bytes */;
};

struct MDeformWeight {
    int def_nr /* 4 bytes */;
    float weight /* 4 bytes */;
};

struct MDeformVert {
    MDeformWeight *dw /* 8 bytes */;
    int totweight /* 4 bytes */;
    int flag /* 4 bytes */;
};

struct MVert {
    float co[3] /* 12 bytes */;
    short no[3] /* 6 bytes */;
    char flag /* 1 bytes */;
    char bweight /* 1 bytes */;
};

struct MCol {
    char a /* 1 bytes */;
    char r /* 1 bytes */;
    char g /* 1 bytes */;
    char b /* 1 bytes */;
};

struct MPoly {
    int loopstart /* 4 bytes */;
    int totloop /* 4 bytes */;
    short mat_nr /* 2 bytes */;
    char flag /* 1 bytes */;
    char pad /* 1 bytes */;
};

struct MLoop {
    int v /* 4 bytes */;
    int e /* 4 bytes */;
};

struct MTexPoly {
    Image *tpage /* 8 bytes */;
    char flag /* 1 bytes */;
    char transp /* 1 bytes */;
    short mode /* 2 bytes */;
    short tile /* 2 bytes */;
    short pad /* 2 bytes */;
};

struct MLoopUV {
    float uv[2] /* 8 bytes */;
    int flag /* 4 bytes */;
};

struct MLoopCol {
    char r /* 1 bytes */;
    char g /* 1 bytes */;
    char b /* 1 bytes */;
    char a /* 1 bytes */;
};

struct MSelect {
    int index /* 4 bytes */;
    int type /* 4 bytes */;
};

struct MTFace {
    float uv[4][2] /* 32 bytes */;
    Image *tpage /* 8 bytes */;
    char flag /* 1 bytes */;
    char transp /* 1 bytes */;
    short mode /* 2 bytes */;
    short tile /* 2 bytes */;
    short unwrap /* 2 bytes */;
};

struct MFloatProperty {
    float f /* 4 bytes */;
};

struct MIntProperty {
    int i /* 4 bytes */;
};

struct MStringProperty {
    char s[255] /* 255 bytes */;
    char s_len /* 1 bytes */;
};

struct OrigSpaceFace {
    float uv[4][2] /* 32 bytes */;
};

struct OrigSpaceLoop {
    float uv[2] /* 8 bytes */;
};

struct MDisps {
    int totdisp /* 4 bytes */;
    int level /* 4 bytes */;
    float (*disps)() /* 8 bytes */;
    int *hidden /* 8 bytes */;
};

struct MultiresCol {
    float a /* 4 bytes */;
    float r /* 4 bytes */;
    float g /* 4 bytes */;
    float b /* 4 bytes */;
};

struct MultiresColFace {
    MultiresCol col[4] /* 64 bytes */;
};

struct MultiresFace {
    int v[4] /* 16 bytes */;
    int mid /* 4 bytes */;
    char flag /* 1 bytes */;
    char mat_nr /* 1 bytes */;
    char pad[2] /* 2 bytes */;
};

struct MultiresEdge {
    int v[2] /* 8 bytes */;
    int mid /* 4 bytes */;
};

struct MultiresLevel {
    MultiresLevel *next /* 8 bytes */;
    MultiresLevel *prev /* 8 bytes */;
    MultiresFace *faces /* 8 bytes */;
    MultiresColFace *colfaces /* 8 bytes */;
    MultiresEdge *edges /* 8 bytes */;
    int totvert /* 4 bytes */;
    int totface /* 4 bytes */;
    int totedge /* 4 bytes */;
    int pad /* 4 bytes */;
    MVert *verts /* 8 bytes */;
};

struct Multires {
    ListBase levels /* 16 bytes */;
    MVert *verts /* 8 bytes */;
    char level_count /* 1 bytes */;
    char current /* 1 bytes */;
    char newlvl /* 1 bytes */;
    char edgelvl /* 1 bytes */;
    char pinlvl /* 1 bytes */;
    char renderlvl /* 1 bytes */;
    char use_col /* 1 bytes */;
    char flag /* 1 bytes */;
    CustomData vdata /* 208 bytes */;
    CustomData fdata /* 208 bytes */;
    short *edge_flags /* 8 bytes */;
    char *edge_creases /* 8 bytes */;
};

struct MRecast {
    int i /* 4 bytes */;
};

struct GridPaintMask {
    float *data /* 8 bytes */;
    int level /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct MVertSkin {
    float radius[3] /* 12 bytes */;
    int flag /* 4 bytes */;
};

struct FreestyleEdge {
    char flag /* 1 bytes */;
    char pad[3] /* 3 bytes */;
};

struct FreestyleFace {
    char flag /* 1 bytes */;
    char pad[3] /* 3 bytes */;
};

struct ModifierData {
    ModifierData *next /* 8 bytes */;
    ModifierData *prev /* 8 bytes */;
    int type /* 4 bytes */;
    int mode /* 4 bytes */;
    int stackindex /* 4 bytes */;
    int pad /* 4 bytes */;
    char name[64] /* 64 bytes */;
    Scene *scene /* 8 bytes */;
    char *error /* 8 bytes */;
};

struct MappingInfoModifierData {
    ModifierData modifier /* 112 bytes */;
    Tex *texture /* 8 bytes */;
    Object *map_object /* 8 bytes */;
    char uvlayer_name[64] /* 64 bytes */;
    int uvlayer_tmp /* 4 bytes */;
    int texmapping /* 4 bytes */;
};

struct SubsurfModifierData {
    ModifierData modifier /* 112 bytes */;
    short subdivType /* 2 bytes */;
    short levels /* 2 bytes */;
    short renderLevels /* 2 bytes */;
    short flags /* 2 bytes */;
    void *emCache /* 8 bytes */;
    void *mCache /* 8 bytes */;
};

struct LatticeModifierData {
    ModifierData modifier /* 112 bytes */;
    Object *object /* 8 bytes */;
    char name[64] /* 64 bytes */;
    float strength /* 4 bytes */;
    char pad[4] /* 4 bytes */;
};

struct CurveModifierData {
    ModifierData modifier /* 112 bytes */;
    Object *object /* 8 bytes */;
    char name[64] /* 64 bytes */;
    short defaxis /* 2 bytes */;
    char pad[6] /* 6 bytes */;
};

struct BuildModifierData {
    ModifierData modifier /* 112 bytes */;
    float start /* 4 bytes */;
    float length /* 4 bytes */;
    short flag /* 2 bytes */;
    short randomize /* 2 bytes */;
    int seed /* 4 bytes */;
};

struct MaskModifierData {
    ModifierData modifier /* 112 bytes */;
    Object *ob_arm /* 8 bytes */;
    char vgroup[64] /* 64 bytes */;
    int mode /* 4 bytes */;
    int flag /* 4 bytes */;
};

struct ArrayModifierData {
    ModifierData modifier /* 112 bytes */;
    Object *start_cap /* 8 bytes */;
    Object *end_cap /* 8 bytes */;
    Object *curve_ob /* 8 bytes */;
    Object *offset_ob /* 8 bytes */;
    float offset[3] /* 12 bytes */;
    float scale[3] /* 12 bytes */;
    float length /* 4 bytes */;
    float merge_dist /* 4 bytes */;
    int fit_type /* 4 bytes */;
    int offset_type /* 4 bytes */;
    int flags /* 4 bytes */;
    int count /* 4 bytes */;
};

struct MirrorModifierData {
    ModifierData modifier /* 112 bytes */;
    short axis /* 2 bytes */;
    short flag /* 2 bytes */;
    float tolerance /* 4 bytes */;
    Object *mirror_ob /* 8 bytes */;
};

struct EdgeSplitModifierData {
    ModifierData modifier /* 112 bytes */;
    float split_angle /* 4 bytes */;
    int flags /* 4 bytes */;
};

struct BevelModifierData {
    ModifierData modifier /* 112 bytes */;
    float value /* 4 bytes */;
    int res /* 4 bytes */;
    short flags /* 2 bytes */;
    short val_flags /* 2 bytes */;
    short lim_flags /* 2 bytes */;
    short e_flags /* 2 bytes */;
    short mat /* 2 bytes */;
    short pad /* 2 bytes */;
    int pad2 /* 4 bytes */;
    float profile /* 4 bytes */;
    float bevel_angle /* 4 bytes */;
    char defgrp_name[64] /* 64 bytes */;
};

struct SmokeModifierData {
    ModifierData modifier /* 112 bytes */;
    SmokeDomainSettings *domain /* 8 bytes */;
    SmokeFlowSettings *flow /* 8 bytes */;
    SmokeCollSettings *coll /* 8 bytes */;
    float time /* 4 bytes */;
    int type /* 4 bytes */;
};

struct DisplaceModifierData {
    ModifierData modifier /* 112 bytes */;
    Tex *texture /* 8 bytes */;
    Object *map_object /* 8 bytes */;
    char uvlayer_name[64] /* 64 bytes */;
    int uvlayer_tmp /* 4 bytes */;
    int texmapping /* 4 bytes */;
    float strength /* 4 bytes */;
    int direction /* 4 bytes */;
    char defgrp_name[64] /* 64 bytes */;
    float midlevel /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct UVProjectModifierData {
    ModifierData modifier /* 112 bytes */;
    Object *projectors[10] /* 80 bytes */;
    Image *image /* 8 bytes */;
    int flags /* 4 bytes */;
    int num_projectors /* 4 bytes */;
    float aspectx /* 4 bytes */;
    float aspecty /* 4 bytes */;
    float scalex /* 4 bytes */;
    float scaley /* 4 bytes */;
    char uvlayer_name[64] /* 64 bytes */;
    int uvlayer_tmp /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct DecimateModifierData {
    ModifierData modifier /* 112 bytes */;
    float percent /* 4 bytes */;
    short iter /* 2 bytes */;
    char delimit /* 1 bytes */;
    char pad /* 1 bytes */;
    float angle /* 4 bytes */;
    char defgrp_name[64] /* 64 bytes */;
    short flag /* 2 bytes */;
    short mode /* 2 bytes */;
    int face_count /* 4 bytes */;
    int pad2 /* 4 bytes */;
};

struct SmoothModifierData {
    ModifierData modifier /* 112 bytes */;
    float fac /* 4 bytes */;
    char defgrp_name[64] /* 64 bytes */;
    short flag /* 2 bytes */;
    short repeat /* 2 bytes */;
};

struct CastModifierData {
    ModifierData modifier /* 112 bytes */;
    Object *object /* 8 bytes */;
    float fac /* 4 bytes */;
    float radius /* 4 bytes */;
    float size /* 4 bytes */;
    char defgrp_name[64] /* 64 bytes */;
    short flag /* 2 bytes */;
    short type /* 2 bytes */;
};

struct WaveModifierData {
    ModifierData modifier /* 112 bytes */;
    Tex *texture /* 8 bytes */;
    Object *map_object /* 8 bytes */;
    char uvlayer_name[64] /* 64 bytes */;
    int uvlayer_tmp /* 4 bytes */;
    int texmapping /* 4 bytes */;
    Object *objectcenter /* 8 bytes */;
    char defgrp_name[64] /* 64 bytes */;
    short flag /* 2 bytes */;
    short pad /* 2 bytes */;
    float startx /* 4 bytes */;
    float starty /* 4 bytes */;
    float height /* 4 bytes */;
    float width /* 4 bytes */;
    float narrow /* 4 bytes */;
    float speed /* 4 bytes */;
    float damp /* 4 bytes */;
    float falloff /* 4 bytes */;
    float timeoffs /* 4 bytes */;
    float lifetime /* 4 bytes */;
    float pad1 /* 4 bytes */;
};

struct ArmatureModifierData {
    ModifierData modifier /* 112 bytes */;
    short deformflag /* 2 bytes */;
    short multi /* 2 bytes */;
    int pad2 /* 4 bytes */;
    Object *object /* 8 bytes */;
    float *prevCos /* 8 bytes */;
    char defgrp_name[64] /* 64 bytes */;
};

struct HookModifierData {
    ModifierData modifier /* 112 bytes */;
    Object *object /* 8 bytes */;
    char subtarget[64] /* 64 bytes */;
    char flag /* 1 bytes */;
    char falloff_type /* 1 bytes */;
    char pad[6] /* 6 bytes */;
    float parentinv[4][4] /* 64 bytes */;
    float cent[3] /* 12 bytes */;
    float falloff /* 4 bytes */;
    CurveMapping *curfalloff /* 8 bytes */;
    int *indexar /* 8 bytes */;
    int totindex /* 4 bytes */;
    float force /* 4 bytes */;
    char name[64] /* 64 bytes */;
};

struct SoftbodyModifierData {
    ModifierData modifier /* 112 bytes */;
};

struct ClothModifierData {
    ModifierData modifier /* 112 bytes */;
    Scene *scene /* 8 bytes */;
    void *clothObject /* 8 bytes */;
    ClothSimSettings *sim_parms /* 8 bytes */;
    ClothCollSettings *coll_parms /* 8 bytes */;
    PointCache *point_cache /* 8 bytes */;
    ListBase ptcaches /* 16 bytes */;
    void *hairdata /* 8 bytes */;
    float hair_grid_min[3] /* 12 bytes */;
    float hair_grid_max[3] /* 12 bytes */;
    int hair_grid_res[3] /* 12 bytes */;
    float hair_grid_cellsize /* 4 bytes */;
    void *solver_result /* 8 bytes */;
};

struct CollisionModifierData {
    ModifierData modifier /* 112 bytes */;
    MVert *x /* 8 bytes */;
    MVert *xnew /* 8 bytes */;
    MVert *xold /* 8 bytes */;
    MVert *current_xnew /* 8 bytes */;
    MVert *current_x /* 8 bytes */;
    MVert *current_v /* 8 bytes */;
    MFace *mfaces /* 8 bytes */;
    int numverts /* 4 bytes */;
    int numfaces /* 4 bytes */;
    float time_x /* 4 bytes */;
    float time_xnew /* 4 bytes */;
    void *bvhtree /* 8 bytes */;
};

struct SurfaceModifierData {
    ModifierData modifier /* 112 bytes */;
    MVert *x /* 8 bytes */;
    MVert *v /* 8 bytes */;
    void *dm /* 8 bytes */;
    void *bvhtree /* 8 bytes */;
    int cfra /* 4 bytes */;
    int numverts /* 4 bytes */;
};

struct BooleanModifierData {
    ModifierData modifier /* 112 bytes */;
    Object *object /* 8 bytes */;
    int operation /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct MDefInfluence {
    int vertex /* 4 bytes */;
    float weight /* 4 bytes */;
};

struct MDefCell {
    int offset /* 4 bytes */;
    int totinfluence /* 4 bytes */;
};

struct MeshDeformModifierData {
    ModifierData modifier /* 112 bytes */;
    Object *object /* 8 bytes */;
    char defgrp_name[64] /* 64 bytes */;
    short gridsize /* 2 bytes */;
    short flag /* 2 bytes */;
    short pad[2] /* 4 bytes */;
    MDefInfluence *bindinfluences /* 8 bytes */;
    int *bindoffsets /* 8 bytes */;
    float *bindcagecos /* 8 bytes */;
    int totvert /* 4 bytes */;
    int totcagevert /* 4 bytes */;
    MDefCell *dyngrid /* 8 bytes */;
    MDefInfluence *dyninfluences /* 8 bytes */;
    int *dynverts /* 8 bytes */;
    int dyngridsize /* 4 bytes */;
    int totinfluence /* 4 bytes */;
    float dyncellmin[3] /* 12 bytes */;
    float dyncellwidth /* 4 bytes */;
    float bindmat[4][4] /* 64 bytes */;
    float *bindweights /* 8 bytes */;
    float *bindcos /* 8 bytes */;
    void (*bindfunc)() /* 8 bytes */;
};

struct ParticleSystemModifierData {
    ModifierData modifier /* 112 bytes */;
    ParticleSystem *psys /* 8 bytes */;
    void *dm /* 8 bytes */;
    int totdmvert /* 4 bytes */;
    int totdmedge /* 4 bytes */;
    int totdmface /* 4 bytes */;
    short flag /* 2 bytes */;
    short pad /* 2 bytes */;
};

struct ParticleInstanceModifierData {
    ModifierData modifier /* 112 bytes */;
    Object *ob /* 8 bytes */;
    short psys /* 2 bytes */;
    short flag /* 2 bytes */;
    short axis /* 2 bytes */;
    short pad /* 2 bytes */;
    float position /* 4 bytes */;
    float random_position /* 4 bytes */;
};

struct ExplodeModifierData {
    ModifierData modifier /* 112 bytes */;
    int *facepa /* 8 bytes */;
    short flag /* 2 bytes */;
    short vgroup /* 2 bytes */;
    float protect /* 4 bytes */;
    char uvname[64] /* 64 bytes */;
};

struct MultiresModifierData {
    ModifierData modifier /* 112 bytes */;
    char lvl /* 1 bytes */;
    char sculptlvl /* 1 bytes */;
    char renderlvl /* 1 bytes */;
    char totlvl /* 1 bytes */;
    char simple /* 1 bytes */;
    char flags /* 1 bytes */;
    char pad[2] /* 2 bytes */;
};

struct FluidsimModifierData {
    ModifierData modifier /* 112 bytes */;
    FluidsimSettings *fss /* 8 bytes */;
    PointCache *point_cache /* 8 bytes */;
};

struct ShrinkwrapModifierData {
    ModifierData modifier /* 112 bytes */;
    Object *target /* 8 bytes */;
    Object *auxTarget /* 8 bytes */;
    char vgroup_name[64] /* 64 bytes */;
    float keepDist /* 4 bytes */;
    short shrinkType /* 2 bytes */;
    char shrinkOpts /* 1 bytes */;
    char pad1 /* 1 bytes */;
    float projLimit /* 4 bytes */;
    char projAxis /* 1 bytes */;
    char subsurfLevels /* 1 bytes */;
    char pad[2] /* 2 bytes */;
};

struct SimpleDeformModifierData {
    ModifierData modifier /* 112 bytes */;
    Object *origin /* 8 bytes */;
    char vgroup_name[64] /* 64 bytes */;
    float factor /* 4 bytes */;
    float limit[2] /* 8 bytes */;
    char mode /* 1 bytes */;
    char axis /* 1 bytes */;
    char pad[2] /* 2 bytes */;
};

struct ShapeKeyModifierData {
    ModifierData modifier /* 112 bytes */;
};

struct SolidifyModifierData {
    ModifierData modifier /* 112 bytes */;
    char defgrp_name[64] /* 64 bytes */;
    float offset /* 4 bytes */;
    float offset_fac /* 4 bytes */;
    float offset_fac_vg /* 4 bytes */;
    float offset_clamp /* 4 bytes */;
    float pad /* 4 bytes */;
    float crease_inner /* 4 bytes */;
    float crease_outer /* 4 bytes */;
    float crease_rim /* 4 bytes */;
    int flag /* 4 bytes */;
    short mat_ofs /* 2 bytes */;
    short mat_ofs_rim /* 2 bytes */;
};

struct ScrewModifierData {
    ModifierData modifier /* 112 bytes */;
    Object *ob_axis /* 8 bytes */;
    int steps /* 4 bytes */;
    int render_steps /* 4 bytes */;
    int iter /* 4 bytes */;
    float screw_ofs /* 4 bytes */;
    float angle /* 4 bytes */;
    char axis /* 1 bytes */;
    char pad /* 1 bytes */;
    short flag /* 2 bytes */;
};

struct OceanModifierData {
    ModifierData modifier /* 112 bytes */;
    void *ocean /* 8 bytes */;
    void *oceancache /* 8 bytes */;
    int resolution /* 4 bytes */;
    int spatial_size /* 4 bytes */;
    float wind_velocity /* 4 bytes */;
    float damp /* 4 bytes */;
    float smallest_wave /* 4 bytes */;
    float depth /* 4 bytes */;
    float wave_alignment /* 4 bytes */;
    float wave_direction /* 4 bytes */;
    float wave_scale /* 4 bytes */;
    float chop_amount /* 4 bytes */;
    float foam_coverage /* 4 bytes */;
    float time /* 4 bytes */;
    int bakestart /* 4 bytes */;
    int bakeend /* 4 bytes */;
    char cachepath[1024] /* 1024 bytes */;
    char foamlayername[64] /* 64 bytes */;
    char cached /* 1 bytes */;
    char geometry_mode /* 1 bytes */;
    char flag /* 1 bytes */;
    char refresh /* 1 bytes */;
    short repeat_x /* 2 bytes */;
    short repeat_y /* 2 bytes */;
    int seed /* 4 bytes */;
    float size /* 4 bytes */;
    float foam_fade /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct WarpModifierData {
    ModifierData modifier /* 112 bytes */;
    Tex *texture /* 8 bytes */;
    Object *map_object /* 8 bytes */;
    char uvlayer_name[64] /* 64 bytes */;
    int uvlayer_tmp /* 4 bytes */;
    int texmapping /* 4 bytes */;
    Object *object_from /* 8 bytes */;
    Object *object_to /* 8 bytes */;
    CurveMapping *curfalloff /* 8 bytes */;
    char defgrp_name[64] /* 64 bytes */;
    float strength /* 4 bytes */;
    float falloff_radius /* 4 bytes */;
    char flag /* 1 bytes */;
    char falloff_type /* 1 bytes */;
    char pad[6] /* 6 bytes */;
};

struct WeightVGEditModifierData {
    ModifierData modifier /* 112 bytes */;
    char defgrp_name[64] /* 64 bytes */;
    short edit_flags /* 2 bytes */;
    short falloff_type /* 2 bytes */;
    float default_weight /* 4 bytes */;
    CurveMapping *cmap_curve /* 8 bytes */;
    float add_threshold /* 4 bytes */;
    float rem_threshold /* 4 bytes */;
    float mask_constant /* 4 bytes */;
    char mask_defgrp_name[64] /* 64 bytes */;
    int mask_tex_use_channel /* 4 bytes */;
    Tex *mask_texture /* 8 bytes */;
    Object *mask_tex_map_obj /* 8 bytes */;
    int mask_tex_mapping /* 4 bytes */;
    char mask_tex_uvlayer_name[64] /* 64 bytes */;
    int pad_i1 /* 4 bytes */;
};

struct WeightVGMixModifierData {
    ModifierData modifier /* 112 bytes */;
    char defgrp_name_a[64] /* 64 bytes */;
    char defgrp_name_b[64] /* 64 bytes */;
    float default_weight_a /* 4 bytes */;
    float default_weight_b /* 4 bytes */;
    char mix_mode /* 1 bytes */;
    char mix_set /* 1 bytes */;
    char pad_c1[6] /* 6 bytes */;
    float mask_constant /* 4 bytes */;
    char mask_defgrp_name[64] /* 64 bytes */;
    int mask_tex_use_channel /* 4 bytes */;
    Tex *mask_texture /* 8 bytes */;
    Object *mask_tex_map_obj /* 8 bytes */;
    int mask_tex_mapping /* 4 bytes */;
    char mask_tex_uvlayer_name[64] /* 64 bytes */;
    int pad_i1 /* 4 bytes */;
};

struct WeightVGProximityModifierData {
    ModifierData modifier /* 112 bytes */;
    char defgrp_name[64] /* 64 bytes */;
    int proximity_mode /* 4 bytes */;
    int proximity_flags /* 4 bytes */;
    Object *proximity_ob_target /* 8 bytes */;
    float mask_constant /* 4 bytes */;
    char mask_defgrp_name[64] /* 64 bytes */;
    int mask_tex_use_channel /* 4 bytes */;
    Tex *mask_texture /* 8 bytes */;
    Object *mask_tex_map_obj /* 8 bytes */;
    int mask_tex_mapping /* 4 bytes */;
    char mask_tex_uvlayer_name[64] /* 64 bytes */;
    float min_dist /* 4 bytes */;
    float max_dist /* 4 bytes */;
    short falloff_type /* 2 bytes */;
    short pad_s1 /* 2 bytes */;
};

struct DynamicPaintModifierData {
    ModifierData modifier /* 112 bytes */;
    DynamicPaintCanvasSettings *canvas /* 8 bytes */;
    DynamicPaintBrushSettings *brush /* 8 bytes */;
    int type /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct RemeshModifierData {
    ModifierData modifier /* 112 bytes */;
    float threshold /* 4 bytes */;
    float scale /* 4 bytes */;
    float hermite_num /* 4 bytes */;
    char depth /* 1 bytes */;
    char flag /* 1 bytes */;
    char mode /* 1 bytes */;
    char pad /* 1 bytes */;
};

struct SkinModifierData {
    ModifierData modifier /* 112 bytes */;
    float branch_smoothing /* 4 bytes */;
    char flag /* 1 bytes */;
    char symmetry_axes /* 1 bytes */;
    char pad[2] /* 2 bytes */;
};

struct TriangulateModifierData {
    ModifierData modifier /* 112 bytes */;
    int flag /* 4 bytes */;
    int quad_method /* 4 bytes */;
    int ngon_method /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct LaplacianSmoothModifierData {
    ModifierData modifier /* 112 bytes */;
    float lambda /* 4 bytes */;
    float lambda_border /* 4 bytes */;
    float pad1 /* 4 bytes */;
    char defgrp_name[64] /* 64 bytes */;
    short flag /* 2 bytes */;
    short repeat /* 2 bytes */;
};

struct UVWarpModifierData {
    ModifierData modifier /* 112 bytes */;
    char axis_u /* 1 bytes */;
    char axis_v /* 1 bytes */;
    char pad[6] /* 6 bytes */;
    float center[2] /* 8 bytes */;
    Object *object_src /* 8 bytes */;
    char bone_src[64] /* 64 bytes */;
    Object *object_dst /* 8 bytes */;
    char bone_dst[64] /* 64 bytes */;
    char vgroup_name[64] /* 64 bytes */;
    char uvlayer_name[64] /* 64 bytes */;
};

struct MeshCacheModifierData {
    ModifierData modifier /* 112 bytes */;
    char flag /* 1 bytes */;
    char type /* 1 bytes */;
    char time_mode /* 1 bytes */;
    char play_mode /* 1 bytes */;
    char forward_axis /* 1 bytes */;
    char up_axis /* 1 bytes */;
    char flip_axis /* 1 bytes */;
    char interp /* 1 bytes */;
    float factor /* 4 bytes */;
    char deform_mode /* 1 bytes */;
    char pad[7] /* 7 bytes */;
    float frame_start /* 4 bytes */;
    float frame_scale /* 4 bytes */;
    float eval_frame /* 4 bytes */;
    float eval_time /* 4 bytes */;
    float eval_factor /* 4 bytes */;
    char filepath[1024] /* 1024 bytes */;
};

struct LaplacianDeformModifierData {
    ModifierData modifier /* 112 bytes */;
    char anchor_grp_name[64] /* 64 bytes */;
    int total_verts /* 4 bytes */;
    int repeat /* 4 bytes */;
    float *vertexco /* 8 bytes */;
    void *cache_system /* 8 bytes */;
    short flag /* 2 bytes */;
    short pad[3] /* 6 bytes */;
};

struct WireframeModifierData {
    ModifierData modifier /* 112 bytes */;
    char defgrp_name[64] /* 64 bytes */;
    float offset /* 4 bytes */;
    float offset_fac /* 4 bytes */;
    float offset_fac_vg /* 4 bytes */;
    float crease_weight /* 4 bytes */;
    short flag /* 2 bytes */;
    short mat_ofs /* 2 bytes */;
    short pad[2] /* 4 bytes */;
};

struct DataTransferModifierData {
    ModifierData modifier /* 112 bytes */;
    Object *ob_source /* 8 bytes */;
    int data_types /* 4 bytes */;
    int vmap_mode /* 4 bytes */;
    int emap_mode /* 4 bytes */;
    int lmap_mode /* 4 bytes */;
    int pmap_mode /* 4 bytes */;
    float map_max_distance /* 4 bytes */;
    float map_ray_radius /* 4 bytes */;
    float islands_precision /* 4 bytes */;
    int pad_i1 /* 4 bytes */;
    int layers_select_src[4] /* 16 bytes */;
    int layers_select_dst[4] /* 16 bytes */;
    int mix_mode /* 4 bytes */;
    float mix_factor /* 4 bytes */;
    char defgrp_name[64] /* 64 bytes */;
    int flags /* 4 bytes */;
};

struct NormalEditModifierData {
    ModifierData modifier /* 112 bytes */;
    char defgrp_name[64] /* 64 bytes */;
    Object *target /* 8 bytes */;
    short mode /* 2 bytes */;
    short flag /* 2 bytes */;
    short mix_mode /* 2 bytes */;
    char pad[2] /* 2 bytes */;
    float mix_factor /* 4 bytes */;
    float offset[3] /* 12 bytes */;
};

struct EditLatt {
    Lattice *latt /* 8 bytes */;
    int shapenr /* 4 bytes */;
    char pad[4] /* 4 bytes */;
};

struct Lattice {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
    short pntsu /* 2 bytes */;
    short pntsv /* 2 bytes */;
    short pntsw /* 2 bytes */;
    short flag /* 2 bytes */;
    short opntsu /* 2 bytes */;
    short opntsv /* 2 bytes */;
    short opntsw /* 2 bytes */;
    short pad2 /* 2 bytes */;
    char typeu /* 1 bytes */;
    char typev /* 1 bytes */;
    char typew /* 1 bytes */;
    char pad3 /* 1 bytes */;
    int actbp /* 4 bytes */;
    float fu /* 4 bytes */;
    float fv /* 4 bytes */;
    float fw /* 4 bytes */;
    float du /* 4 bytes */;
    float dv /* 4 bytes */;
    float dw /* 4 bytes */;
    BPoint *def /* 8 bytes */;
    Ipo *ipo /* 8 bytes */;
    Key *key /* 8 bytes */;
    MDeformVert *dvert /* 8 bytes */;
    char vgroup[64] /* 64 bytes */;
    EditLatt *editlatt /* 8 bytes */;
};

struct bDeformGroup {
    bDeformGroup *next /* 8 bytes */;
    bDeformGroup *prev /* 8 bytes */;
    char name[64] /* 64 bytes */;
    char flag /* 1 bytes */;
    char pad[7] /* 7 bytes */;
};

struct BoundBox {
    float vec[8][3] /* 96 bytes */;
    int flag /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct LodLevel {
    LodLevel *next /* 8 bytes */;
    LodLevel *prev /* 8 bytes */;
    Object *source /* 8 bytes */;
    int flags /* 4 bytes */;
    float distance /* 4 bytes */;
};

struct bAnimVizSettings {
    int ghost_sf /* 4 bytes */;
    int ghost_ef /* 4 bytes */;
    int ghost_bc /* 4 bytes */;
    int ghost_ac /* 4 bytes */;
    short ghost_type /* 2 bytes */;
    short ghost_step /* 2 bytes */;
    short ghost_flag /* 2 bytes */;
    short recalc /* 2 bytes */;
    short path_type /* 2 bytes */;
    short path_step /* 2 bytes */;
    short path_viewflag /* 2 bytes */;
    short path_bakeflag /* 2 bytes */;
    int path_sf /* 4 bytes */;
    int path_ef /* 4 bytes */;
    int path_bc /* 4 bytes */;
    int path_ac /* 4 bytes */;
};

struct Object {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
    void *sculpt /* 8 bytes */;
    short type /* 2 bytes */;
    short partype /* 2 bytes */;
    int par1 /* 4 bytes */;
    int par2 /* 4 bytes */;
    int par3 /* 4 bytes */;
    char parsubstr[64] /* 64 bytes */;
    Object *parent /* 8 bytes */;
    Object *track /* 8 bytes */;
    Object *proxy /* 8 bytes */;
    Object *proxy_group /* 8 bytes */;
    Object *proxy_from /* 8 bytes */;
    Ipo *ipo /* 8 bytes */;
    BoundBox *bb /* 8 bytes */;
    bAction *action /* 8 bytes */;
    bAction *poselib /* 8 bytes */;
    bPose *pose /* 8 bytes */;
    void *data /* 8 bytes */;
    bGPdata *gpd /* 8 bytes */;
    bAnimVizSettings avs /* 48 bytes */;
    bMotionPath *mpath /* 8 bytes */;
    ListBase constraintChannels /* 16 bytes */;
    ListBase effect /* 16 bytes */;
    ListBase defbase /* 16 bytes */;
    ListBase modifiers /* 16 bytes */;
    int mode /* 4 bytes */;
    int restore_mode /* 4 bytes */;
    Material **mat /* 8 bytes */;
    char *matbits /* 8 bytes */;
    int totcol /* 4 bytes */;
    int actcol /* 4 bytes */;
    float loc[3] /* 12 bytes */;
    float dloc[3] /* 12 bytes */;
    float orig[3] /* 12 bytes */;
    float size[3] /* 12 bytes */;
    float dsize[3] /* 12 bytes */;
    float dscale[3] /* 12 bytes */;
    float rot[3] /* 12 bytes */;
    float drot[3] /* 12 bytes */;
    float quat[4] /* 16 bytes */;
    float dquat[4] /* 16 bytes */;
    float rotAxis[3] /* 12 bytes */;
    float drotAxis[3] /* 12 bytes */;
    float rotAngle /* 4 bytes */;
    float drotAngle /* 4 bytes */;
    float obmat[4][4] /* 64 bytes */;
    float parentinv[4][4] /* 64 bytes */;
    float constinv[4][4] /* 64 bytes */;
    float imat[4][4] /* 64 bytes */;
    float imat_ren[4][4] /* 64 bytes */;
    int lay /* 4 bytes */;
    short flag /* 2 bytes */;
    short colbits /* 2 bytes */;
    short transflag /* 2 bytes */;
    short protectflag /* 2 bytes */;
    short trackflag /* 2 bytes */;
    short upflag /* 2 bytes */;
    short nlaflag /* 2 bytes */;
    short ipoflag /* 2 bytes */;
    short scaflag /* 2 bytes */;
    char scavisflag /* 1 bytes */;
    char depsflag /* 1 bytes */;
    int dupon /* 4 bytes */;
    int dupoff /* 4 bytes */;
    int dupsta /* 4 bytes */;
    int dupend /* 4 bytes */;
    int pad /* 4 bytes */;
    float mass /* 4 bytes */;
    float damping /* 4 bytes */;
    float inertia /* 4 bytes */;
    float formfactor /* 4 bytes */;
    float rdamping /* 4 bytes */;
    float margin /* 4 bytes */;
    float max_vel /* 4 bytes */;
    float min_vel /* 4 bytes */;
    float obstacleRad /* 4 bytes */;
    float step_height /* 4 bytes */;
    float jump_speed /* 4 bytes */;
    float fall_speed /* 4 bytes */;
    short col_group /* 2 bytes */;
    short col_mask /* 2 bytes */;
    short rotmode /* 2 bytes */;
    char boundtype /* 1 bytes */;
    char collision_boundtype /* 1 bytes */;
    short dtx /* 2 bytes */;
    char dt /* 1 bytes */;
    char empty_drawtype /* 1 bytes */;
    float empty_drawsize /* 4 bytes */;
    float dupfacesca /* 4 bytes */;
    ListBase prop /* 16 bytes */;
    ListBase sensors /* 16 bytes */;
    ListBase controllers /* 16 bytes */;
    ListBase actuators /* 16 bytes */;
    float sf /* 4 bytes */;
    short index /* 2 bytes */;
    short actdef /* 2 bytes */;
    float col[4] /* 16 bytes */;
    int gameflag /* 4 bytes */;
    int gameflag2 /* 4 bytes */;
    BulletSoftBody *bsoft /* 8 bytes */;
    char restrictflag /* 1 bytes */;
    char recalc /* 1 bytes */;
    short softflag /* 2 bytes */;
    float anisotropicFriction[3] /* 12 bytes */;
    ListBase constraints /* 16 bytes */;
    ListBase nlastrips /* 16 bytes */;
    ListBase hooks /* 16 bytes */;
    ListBase particlesystem /* 16 bytes */;
    PartDeflect *pd /* 8 bytes */;
    SoftBody *soft /* 8 bytes */;
    Group *dup_group /* 8 bytes */;
    char body_type /* 1 bytes */;
    char shapeflag /* 1 bytes */;
    short shapenr /* 2 bytes */;
    float smoothresh /* 4 bytes */;
    FluidsimSettings *fluidsimSettings /* 8 bytes */;
    void *curve_cache /* 8 bytes */;
    void *derivedDeform /* 8 bytes */;
    void *derivedFinal /* 8 bytes */;
    uint64_t lastDataMask /* 8 bytes */;
    uint64_t customdata_mask /* 8 bytes */;
    int state /* 4 bytes */;
    int init_state /* 4 bytes */;
    ListBase gpulamp /* 16 bytes */;
    ListBase pc_ids /* 16 bytes */;
    ListBase *duplilist /* 8 bytes */;
    RigidBodyOb *rigidbody_object /* 8 bytes */;
    RigidBodyCon *rigidbody_constraint /* 8 bytes */;
    float ima_ofs[2] /* 8 bytes */;
    ImageUser *iuser /* 8 bytes */;
    ListBase lodlevels /* 16 bytes */;
    LodLevel *currentlod /* 8 bytes */;
};

struct ObHook {
    ObHook *next /* 8 bytes */;
    ObHook *prev /* 8 bytes */;
    Object *parent /* 8 bytes */;
    float parentinv[4][4] /* 64 bytes */;
    float mat[4][4] /* 64 bytes */;
    float cent[3] /* 12 bytes */;
    float falloff /* 4 bytes */;
    char name[64] /* 64 bytes */;
    int *indexar /* 8 bytes */;
    int totindex /* 4 bytes */;
    int curindex /* 4 bytes */;
    short type /* 2 bytes */;
    short active /* 2 bytes */;
    float force /* 4 bytes */;
};

struct DupliObject {
    DupliObject *next /* 8 bytes */;
    DupliObject *prev /* 8 bytes */;
    Object *ob /* 8 bytes */;
    float mat[4][4] /* 64 bytes */;
    float orco[3] /* 12 bytes */;
    float uv[2] /* 8 bytes */;
    short type /* 2 bytes */;
    char no_draw /* 1 bytes */;
    char animated /* 1 bytes */;
    int persistent_id[8] /* 32 bytes */;
    ParticleSystem *particle_system /* 8 bytes */;
};

struct PartDeflect {
    int flag /* 4 bytes */;
    short deflect /* 2 bytes */;
    short forcefield /* 2 bytes */;
    short falloff /* 2 bytes */;
    short shape /* 2 bytes */;
    short tex_mode /* 2 bytes */;
    short kink /* 2 bytes */;
    short kink_axis /* 2 bytes */;
    short zdir /* 2 bytes */;
    float f_strength /* 4 bytes */;
    float f_damp /* 4 bytes */;
    float f_flow /* 4 bytes */;
    float f_size /* 4 bytes */;
    float f_power /* 4 bytes */;
    float maxdist /* 4 bytes */;
    float mindist /* 4 bytes */;
    float f_power_r /* 4 bytes */;
    float maxrad /* 4 bytes */;
    float minrad /* 4 bytes */;
    float pdef_damp /* 4 bytes */;
    float pdef_rdamp /* 4 bytes */;
    float pdef_perm /* 4 bytes */;
    float pdef_frict /* 4 bytes */;
    float pdef_rfrict /* 4 bytes */;
    float pdef_stickness /* 4 bytes */;
    float absorption /* 4 bytes */;
    float pdef_sbdamp /* 4 bytes */;
    float pdef_sbift /* 4 bytes */;
    float pdef_sboft /* 4 bytes */;
    float clump_fac /* 4 bytes */;
    float clump_pow /* 4 bytes */;
    float kink_freq /* 4 bytes */;
    float kink_shape /* 4 bytes */;
    float kink_amp /* 4 bytes */;
    float free_end /* 4 bytes */;
    float tex_nabla /* 4 bytes */;
    Tex *tex /* 8 bytes */;
    void *rng /* 8 bytes */;
    float f_noise /* 4 bytes */;
    int seed /* 4 bytes */;
    Object *f_source /* 8 bytes */;
};

struct EffectorWeights {
    Group *group /* 8 bytes */;
    float weight[14] /* 56 bytes */;
    float global_gravity /* 4 bytes */;
    short flag /* 2 bytes */;
    short rt[3] /* 6 bytes */;
    int pad /* 4 bytes */;
};

struct PTCacheExtra {
    PTCacheExtra *next /* 8 bytes */;
    PTCacheExtra *prev /* 8 bytes */;
    int type /* 4 bytes */;
    int totdata /* 4 bytes */;
    void *data /* 8 bytes */;
};

struct PTCacheMem {
    PTCacheMem *next /* 8 bytes */;
    PTCacheMem *prev /* 8 bytes */;
    int frame /* 4 bytes */;
    int totpoint /* 4 bytes */;
    int data_types /* 4 bytes */;
    int flag /* 4 bytes */;
    void *data[8] /* 64 bytes */;
    void *cur[8] /* 64 bytes */;
    ListBase extradata /* 16 bytes */;
};

struct PointCache {
    PointCache *next /* 8 bytes */;
    PointCache *prev /* 8 bytes */;
    int flag /* 4 bytes */;
    int step /* 4 bytes */;
    int simframe /* 4 bytes */;
    int startframe /* 4 bytes */;
    int endframe /* 4 bytes */;
    int editframe /* 4 bytes */;
    int last_exact /* 4 bytes */;
    int last_valid /* 4 bytes */;
    int pad /* 4 bytes */;
    int totpoint /* 4 bytes */;
    int index /* 4 bytes */;
    short compression /* 2 bytes */;
    short rt /* 2 bytes */;
    char name[64] /* 64 bytes */;
    char prev_name[64] /* 64 bytes */;
    char info[64] /* 64 bytes */;
    char path[1024] /* 1024 bytes */;
    char *cached_frames /* 8 bytes */;
    ListBase mem_cache /* 16 bytes */;
    void *edit /* 8 bytes */;
    void (*free_edit)() /* 8 bytes */;
};

struct SBVertex {
    float vec[4] /* 16 bytes */;
};

struct BulletSoftBody {
    int flag /* 4 bytes */;
    float linStiff /* 4 bytes */;
    float angStiff /* 4 bytes */;
    float volume /* 4 bytes */;
    int viterations /* 4 bytes */;
    int piterations /* 4 bytes */;
    int diterations /* 4 bytes */;
    int citerations /* 4 bytes */;
    float kSRHR_CL /* 4 bytes */;
    float kSKHR_CL /* 4 bytes */;
    float kSSHR_CL /* 4 bytes */;
    float kSR_SPLT_CL /* 4 bytes */;
    float kSK_SPLT_CL /* 4 bytes */;
    float kSS_SPLT_CL /* 4 bytes */;
    float kVCF /* 4 bytes */;
    float kDP /* 4 bytes */;
    float kDG /* 4 bytes */;
    float kLF /* 4 bytes */;
    float kPR /* 4 bytes */;
    float kVC /* 4 bytes */;
    float kDF /* 4 bytes */;
    float kMT /* 4 bytes */;
    float kCHR /* 4 bytes */;
    float kKHR /* 4 bytes */;
    float kSHR /* 4 bytes */;
    float kAHR /* 4 bytes */;
    int collisionflags /* 4 bytes */;
    int numclusteriterations /* 4 bytes */;
    float welding /* 4 bytes */;
    float margin /* 4 bytes */;
};

struct SoftBody {
    int totpoint /* 4 bytes */;
    int totspring /* 4 bytes */;
    void *bpoint /* 8 bytes */;
    void *bspring /* 8 bytes */;
    char pad /* 1 bytes */;
    char msg_lock /* 1 bytes */;
    short msg_value /* 2 bytes */;
    float nodemass /* 4 bytes */;
    char namedVG_Mass[64] /* 64 bytes */;
    float grav /* 4 bytes */;
    float mediafrict /* 4 bytes */;
    float rklimit /* 4 bytes */;
    float physics_speed /* 4 bytes */;
    float goalspring /* 4 bytes */;
    float goalfrict /* 4 bytes */;
    float mingoal /* 4 bytes */;
    float maxgoal /* 4 bytes */;
    float defgoal /* 4 bytes */;
    short vertgroup /* 2 bytes */;
    char namedVG_Softgoal[64] /* 64 bytes */;
    short fuzzyness /* 2 bytes */;
    float inspring /* 4 bytes */;
    float infrict /* 4 bytes */;
    char namedVG_Spring_K[64] /* 64 bytes */;
    int sfra /* 4 bytes */;
    int efra /* 4 bytes */;
    int interval /* 4 bytes */;
    short local /* 2 bytes */;
    short solverflags /* 2 bytes */;
    SBVertex **keys /* 8 bytes */;
    int totpointkey /* 4 bytes */;
    int totkey /* 4 bytes */;
    float secondspring /* 4 bytes */;
    float colball /* 4 bytes */;
    float balldamp /* 4 bytes */;
    float ballstiff /* 4 bytes */;
    short sbc_mode /* 2 bytes */;
    short aeroedge /* 2 bytes */;
    short minloops /* 2 bytes */;
    short maxloops /* 2 bytes */;
    short choke /* 2 bytes */;
    short solver_ID /* 2 bytes */;
    short plastic /* 2 bytes */;
    short springpreload /* 2 bytes */;
    void *scratch /* 8 bytes */;
    float shearstiff /* 4 bytes */;
    float inpush /* 4 bytes */;
    PointCache *pointcache /* 8 bytes */;
    ListBase ptcaches /* 16 bytes */;
    EffectorWeights *effector_weights /* 8 bytes */;
    float lcom[3] /* 12 bytes */;
    float lrot[3][3] /* 36 bytes */;
    float lscale[3][3] /* 36 bytes */;
    int last_frame /* 4 bytes */;
};

struct FluidVertexVelocity {
    float vel[3] /* 12 bytes */;
};

struct FluidsimSettings {
    FluidsimModifierData *fmd /* 8 bytes */;
    int threads /* 4 bytes */;
    int pad1 /* 4 bytes */;
    short type /* 2 bytes */;
    short show_advancedoptions /* 2 bytes */;
    short resolutionxyz /* 2 bytes */;
    short previewresxyz /* 2 bytes */;
    float realsize /* 4 bytes */;
    short guiDisplayMode /* 2 bytes */;
    short renderDisplayMode /* 2 bytes */;
    float viscosityValue /* 4 bytes */;
    short viscosityMode /* 2 bytes */;
    short viscosityExponent /* 2 bytes */;
    float grav[3] /* 12 bytes */;
    float animStart /* 4 bytes */;
    float animEnd /* 4 bytes */;
    int bakeStart /* 4 bytes */;
    int bakeEnd /* 4 bytes */;
    int frameOffset /* 4 bytes */;
    int pad2 /* 4 bytes */;
    float gstar /* 4 bytes */;
    int maxRefine /* 4 bytes */;
    float iniVelx /* 4 bytes */;
    float iniVely /* 4 bytes */;
    float iniVelz /* 4 bytes */;
    Mesh *orgMesh /* 8 bytes */;
    Mesh *meshBB /* 8 bytes */;
    char surfdataPath[1024] /* 1024 bytes */;
    float bbStart[3] /* 12 bytes */;
    float bbSize[3] /* 12 bytes */;
    Ipo *ipo /* 8 bytes */;
    short typeFlags /* 2 bytes */;
    char domainNovecgen /* 1 bytes */;
    char volumeInitType /* 1 bytes */;
    float partSlipValue /* 4 bytes */;
    int generateTracers /* 4 bytes */;
    float generateParticles /* 4 bytes */;
    float surfaceSmoothing /* 4 bytes */;
    int surfaceSubdivs /* 4 bytes */;
    int flag /* 4 bytes */;
    float particleInfSize /* 4 bytes */;
    float particleInfAlpha /* 4 bytes */;
    float farFieldSize /* 4 bytes */;
    FluidVertexVelocity *meshVelocities /* 8 bytes */;
    int totvert /* 4 bytes */;
    float cpsTimeStart /* 4 bytes */;
    float cpsTimeEnd /* 4 bytes */;
    float cpsQuality /* 4 bytes */;
    float attractforceStrength /* 4 bytes */;
    float attractforceRadius /* 4 bytes */;
    float velocityforceStrength /* 4 bytes */;
    float velocityforceRadius /* 4 bytes */;
    int lastgoodframe /* 4 bytes */;
    float animRate /* 4 bytes */;
};

struct World {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
    short colormodel /* 2 bytes */;
    short totex /* 2 bytes */;
    short texact /* 2 bytes */;
    short mistype /* 2 bytes */;
    float horr /* 4 bytes */;
    float horg /* 4 bytes */;
    float horb /* 4 bytes */;
    float zenr /* 4 bytes */;
    float zeng /* 4 bytes */;
    float zenb /* 4 bytes */;
    float ambr /* 4 bytes */;
    float ambg /* 4 bytes */;
    float ambb /* 4 bytes */;
    float exposure /* 4 bytes */;
    float exp /* 4 bytes */;
    float range /* 4 bytes */;
    float linfac /* 4 bytes */;
    float logfac /* 4 bytes */;
    float gravity /* 4 bytes */;
    float activityBoxRadius /* 4 bytes */;
    short skytype /* 2 bytes */;
    short mode /* 2 bytes */;
    short occlusionRes /* 2 bytes */;
    short physicsEngine /* 2 bytes */;
    short ticrate /* 2 bytes */;
    short maxlogicstep /* 2 bytes */;
    short physubstep /* 2 bytes */;
    short maxphystep /* 2 bytes */;
    float misi /* 4 bytes */;
    float miststa /* 4 bytes */;
    float mistdist /* 4 bytes */;
    float misthi /* 4 bytes */;
    float starr /* 4 bytes */;
    float starg /* 4 bytes */;
    float starb /* 4 bytes */;
    float stark /* 4 bytes */;
    float starsize /* 4 bytes */;
    float starmindist /* 4 bytes */;
    float stardist /* 4 bytes */;
    float starcolnoise /* 4 bytes */;
    short dofsta /* 2 bytes */;
    short dofend /* 2 bytes */;
    short dofmin /* 2 bytes */;
    short dofmax /* 2 bytes */;
    float aodist /* 4 bytes */;
    float aodistfac /* 4 bytes */;
    float aoenergy /* 4 bytes */;
    float aobias /* 4 bytes */;
    short aomode /* 2 bytes */;
    short aosamp /* 2 bytes */;
    short aomix /* 2 bytes */;
    short aocolor /* 2 bytes */;
    float ao_adapt_thresh /* 4 bytes */;
    float ao_adapt_speed_fac /* 4 bytes */;
    float ao_approx_error /* 4 bytes */;
    float ao_approx_correction /* 4 bytes */;
    float ao_indirect_energy /* 4 bytes */;
    float ao_env_energy /* 4 bytes */;
    float ao_pad2 /* 4 bytes */;
    short ao_indirect_bounces /* 2 bytes */;
    short ao_pad /* 2 bytes */;
    short ao_samp_method /* 2 bytes */;
    short ao_gather_method /* 2 bytes */;
    short ao_approx_passes /* 2 bytes */;
    short flag /* 2 bytes */;
    float *aosphere /* 8 bytes */;
    float *aotables /* 8 bytes */;
    Ipo *ipo /* 8 bytes */;
    MTex *mtex[18] /* 144 bytes */;
    short pr_texture /* 2 bytes */;
    short use_nodes /* 2 bytes */;
    short pad[2] /* 4 bytes */;
    PreviewImage *preview /* 8 bytes */;
    bNodeTree *nodetree /* 8 bytes */;
    ListBase gpumaterial /* 16 bytes */;
};

struct Base {
    Base *next /* 8 bytes */;
    Base *prev /* 8 bytes */;
    int lay /* 4 bytes */;
    int selcol /* 4 bytes */;
    int flag /* 4 bytes */;
    short sx /* 2 bytes */;
    short sy /* 2 bytes */;
    Object *object /* 8 bytes */;
};

struct AviCodecData {
    void *lpFormat /* 8 bytes */;
    void *lpParms /* 8 bytes */;
    int cbFormat /* 4 bytes */;
    int cbParms /* 4 bytes */;
    int fccType /* 4 bytes */;
    int fccHandler /* 4 bytes */;
    int dwKeyFrameEvery /* 4 bytes */;
    int dwQuality /* 4 bytes */;
    int dwBytesPerSecond /* 4 bytes */;
    int dwFlags /* 4 bytes */;
    int dwInterleaveEvery /* 4 bytes */;
    int pad /* 4 bytes */;
    char avicodecname[128] /* 128 bytes */;
};

struct QuicktimeCodecData {
    void *cdParms /* 8 bytes */;
    void *pad /* 8 bytes */;
    int cdSize /* 4 bytes */;
    int pad2 /* 4 bytes */;
    char qtcodecname[128] /* 128 bytes */;
};

struct QuicktimeCodecSettings {
    int codecType /* 4 bytes */;
    int codecSpatialQuality /* 4 bytes */;
    int codec /* 4 bytes */;
    int codecFlags /* 4 bytes */;
    int colorDepth /* 4 bytes */;
    int codecTemporalQuality /* 4 bytes */;
    int minSpatialQuality /* 4 bytes */;
    int minTemporalQuality /* 4 bytes */;
    int keyFrameRate /* 4 bytes */;
    int bitRate /* 4 bytes */;
    int audiocodecType /* 4 bytes */;
    int audioSampleRate /* 4 bytes */;
    short audioBitDepth /* 2 bytes */;
    short audioChannels /* 2 bytes */;
    int audioCodecFlags /* 4 bytes */;
    int audioBitRate /* 4 bytes */;
    int pad1 /* 4 bytes */;
};

struct FFMpegCodecData {
    int type /* 4 bytes */;
    int codec /* 4 bytes */;
    int audio_codec /* 4 bytes */;
    int video_bitrate /* 4 bytes */;
    int audio_bitrate /* 4 bytes */;
    int audio_mixrate /* 4 bytes */;
    int audio_channels /* 4 bytes */;
    int audio_pad /* 4 bytes */;
    float audio_volume /* 4 bytes */;
    int gop_size /* 4 bytes */;
    int flags /* 4 bytes */;
    int rc_min_rate /* 4 bytes */;
    int rc_max_rate /* 4 bytes */;
    int rc_buffer_size /* 4 bytes */;
    int mux_packet_size /* 4 bytes */;
    int mux_rate /* 4 bytes */;
    IDProperty *properties /* 8 bytes */;
};

struct AudioData {
    int mixrate /* 4 bytes */;
    float main /* 4 bytes */;
    float speed_of_sound /* 4 bytes */;
    float doppler_factor /* 4 bytes */;
    int distance_model /* 4 bytes */;
    short flag /* 2 bytes */;
    short pad /* 2 bytes */;
    float volume /* 4 bytes */;
    float pad2 /* 4 bytes */;
};

struct FreestyleConfig {
    ListBase modules /* 16 bytes */;
    int mode /* 4 bytes */;
    int raycasting_algorithm /* 4 bytes */;
    int flags /* 4 bytes */;
    float sphere_radius /* 4 bytes */;
    float dkr_epsilon /* 4 bytes */;
    float crease_angle /* 4 bytes */;
    ListBase linesets /* 16 bytes */;
};

struct SceneRenderLayer {
    SceneRenderLayer *next /* 8 bytes */;
    SceneRenderLayer *prev /* 8 bytes */;
    char name[64] /* 64 bytes */;
    Material *mat_override /* 8 bytes */;
    Group *light_override /* 8 bytes */;
    int lay /* 4 bytes */;
    int lay_zmask /* 4 bytes */;
    int lay_exclude /* 4 bytes */;
    int layflag /* 4 bytes */;
    int passflag /* 4 bytes */;
    int pass_xor /* 4 bytes */;
    int samples /* 4 bytes */;
    float pass_alpha_threshold /* 4 bytes */;
    FreestyleConfig freestyleConfig /* 56 bytes */;
};

struct ColorManagedViewSettings {
    int flag /* 4 bytes */;
    int pad /* 4 bytes */;
    char look[64] /* 64 bytes */;
    char view_transform[64] /* 64 bytes */;
    float exposure /* 4 bytes */;
    float gamma /* 4 bytes */;
    CurveMapping *curve_mapping /* 8 bytes */;
    void *pad2 /* 8 bytes */;
};

struct ColorManagedDisplaySettings {
    char display_device[64] /* 64 bytes */;
};

struct ImageFormatData {
    char imtype /* 1 bytes */;
    char depth /* 1 bytes */;
    char planes /* 1 bytes */;
    char flag /* 1 bytes */;
    char quality /* 1 bytes */;
    char compress /* 1 bytes */;
    char exr_codec /* 1 bytes */;
    char cineon_flag /* 1 bytes */;
    short cineon_white /* 2 bytes */;
    short cineon_black /* 2 bytes */;
    float cineon_gamma /* 4 bytes */;
    char jp2_flag /* 1 bytes */;
    char jp2_codec /* 1 bytes */;
    char pad[6] /* 6 bytes */;
    ColorManagedViewSettings view_settings /* 160 bytes */;
    ColorManagedDisplaySettings display_settings /* 64 bytes */;
};

struct BakeData {
    ImageFormatData im_format /* 248 bytes */;
    char filepath[1024] /* 1024 bytes */;
    short width /* 2 bytes */;
    short height /* 2 bytes */;
    short margin /* 2 bytes */;
    short flag /* 2 bytes */;
    float cage_extrusion /* 4 bytes */;
    float pad2 /* 4 bytes */;
    char normal_swizzle[3] /* 3 bytes */;
    char normal_space /* 1 bytes */;
    char save_mode /* 1 bytes */;
    char pad[3] /* 3 bytes */;
    char cage[64] /* 64 bytes */;
};

struct RenderData {
    ImageFormatData im_format /* 248 bytes */;
    AviCodecData *avicodecdata /* 8 bytes */;
    QuicktimeCodecData *qtcodecdata /* 8 bytes */;
    QuicktimeCodecSettings qtcodecsettings /* 64 bytes */;
    FFMpegCodecData ffcodecdata /* 72 bytes */;
    int cfra /* 4 bytes */;
    int sfra /* 4 bytes */;
    int efra /* 4 bytes */;
    float subframe /* 4 bytes */;
    int psfra /* 4 bytes */;
    int pefra /* 4 bytes */;
    int images /* 4 bytes */;
    int framapto /* 4 bytes */;
    short flag /* 2 bytes */;
    short threads /* 2 bytes */;
    float framelen /* 4 bytes */;
    float blurfac /* 4 bytes */;
    float edgeR /* 4 bytes */;
    float edgeG /* 4 bytes */;
    float edgeB /* 4 bytes */;
    short fullscreen /* 2 bytes */;
    short xplay /* 2 bytes */;
    short yplay /* 2 bytes */;
    short freqplay /* 2 bytes */;
    short depth /* 2 bytes */;
    short attrib /* 2 bytes */;
    int frame_step /* 4 bytes */;
    short stereomode /* 2 bytes */;
    short dimensionspreset /* 2 bytes */;
    short filtertype /* 2 bytes */;
    short size /* 2 bytes */;
    short maximsize /* 2 bytes */;
    short pad6 /* 2 bytes */;
    int xsch /* 4 bytes */;
    int ysch /* 4 bytes */;
    short xparts /* 2 bytes */;
    short yparts /* 2 bytes */;
    int tilex /* 4 bytes */;
    int tiley /* 4 bytes */;
    short planes /* 2 bytes */;
    short imtype /* 2 bytes */;
    short subimtype /* 2 bytes */;
    short quality /* 2 bytes */;
    short displaymode /* 2 bytes */;
    char use_lock_interface /* 1 bytes */;
    char pad7 /* 1 bytes */;
    int scemode /* 4 bytes */;
    int mode /* 4 bytes */;
    int raytrace_options /* 4 bytes */;
    short raytrace_structure /* 2 bytes */;
    short pad1 /* 2 bytes */;
    short ocres /* 2 bytes */;
    short pad4 /* 2 bytes */;
    short alphamode /* 2 bytes */;
    short osa /* 2 bytes */;
    short frs_sec /* 2 bytes */;
    short edgeint /* 2 bytes */;
    rctf safety /* 16 bytes */;
    rctf border /* 16 bytes */;
    rcti disprect /* 16 bytes */;
    ListBase layers /* 16 bytes */;
    short actlay /* 2 bytes */;
    short mblur_samples /* 2 bytes */;
    float xasp /* 4 bytes */;
    float yasp /* 4 bytes */;
    float frs_sec_base /* 4 bytes */;
    float gauss /* 4 bytes */;
    int color_mgt_flag /* 4 bytes */;
    float postgamma /* 4 bytes */;
    float posthue /* 4 bytes */;
    float postsat /* 4 bytes */;
    float dither_intensity /* 4 bytes */;
    short bake_osa /* 2 bytes */;
    short bake_filter /* 2 bytes */;
    short bake_mode /* 2 bytes */;
    short bake_flag /* 2 bytes */;
    short bake_normal_space /* 2 bytes */;
    short bake_quad_split /* 2 bytes */;
    float bake_maxdist /* 4 bytes */;
    float bake_biasdist /* 4 bytes */;
    short bake_samples /* 2 bytes */;
    short bake_pad /* 2 bytes */;
    float bake_user_scale /* 4 bytes */;
    float bake_pad1 /* 4 bytes */;
    char pic[1024] /* 1024 bytes */;
    int stamp /* 4 bytes */;
    short stamp_font_id /* 2 bytes */;
    short pad3 /* 2 bytes */;
    char stamp_udata[768] /* 768 bytes */;
    float fg_stamp[4] /* 16 bytes */;
    float bg_stamp[4] /* 16 bytes */;
    char seq_prev_type /* 1 bytes */;
    char seq_rend_type /* 1 bytes */;
    char seq_flag /* 1 bytes */;
    char pad5[5] /* 5 bytes */;
    int simplify_flag /* 4 bytes */;
    short simplify_subsurf /* 2 bytes */;
    short simplify_shadowsamples /* 2 bytes */;
    float simplify_particles /* 4 bytes */;
    float simplify_aosss /* 4 bytes */;
    short cineonwhite /* 2 bytes */;
    short cineonblack /* 2 bytes */;
    float cineongamma /* 4 bytes */;
    short jp2_preset /* 2 bytes */;
    short jp2_depth /* 2 bytes */;
    int rpad3 /* 4 bytes */;
    short domeres /* 2 bytes */;
    short domemode /* 2 bytes */;
    short domeangle /* 2 bytes */;
    short dometilt /* 2 bytes */;
    float domeresbuf /* 4 bytes */;
    float pad2 /* 4 bytes */;
    Text *dometext /* 8 bytes */;
    int line_thickness_mode /* 4 bytes */;
    float unit_line_thickness /* 4 bytes */;
    char engine[32] /* 32 bytes */;
    BakeData bake /* 1360 bytes */;
    int preview_start_resolution /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct RenderProfile {
    RenderProfile *next /* 8 bytes */;
    RenderProfile *prev /* 8 bytes */;
    char name[32] /* 32 bytes */;
    short particle_perc /* 2 bytes */;
    short subsurf_max /* 2 bytes */;
    short shadbufsample_max /* 2 bytes */;
    short pad1 /* 2 bytes */;
    float ao_error /* 4 bytes */;
    float pad2 /* 4 bytes */;
};

struct GameDome {
    short res /* 2 bytes */;
    short mode /* 2 bytes */;
    short angle /* 2 bytes */;
    short tilt /* 2 bytes */;
    float resbuf /* 4 bytes */;
    float pad2 /* 4 bytes */;
    Text *warptext /* 8 bytes */;
};

struct GameFraming {
    float col[3] /* 12 bytes */;
    char type /* 1 bytes */;
    char pad1 /* 1 bytes */;
    char pad2 /* 1 bytes */;
    char pad3 /* 1 bytes */;
};

struct RecastData {
    float cellsize /* 4 bytes */;
    float cellheight /* 4 bytes */;
    float agentmaxslope /* 4 bytes */;
    float agentmaxclimb /* 4 bytes */;
    float agentheight /* 4 bytes */;
    float agentradius /* 4 bytes */;
    float edgemaxlen /* 4 bytes */;
    float edgemaxerror /* 4 bytes */;
    float regionminsize /* 4 bytes */;
    float regionmergesize /* 4 bytes */;
    int vertsperpoly /* 4 bytes */;
    float detailsampledist /* 4 bytes */;
    float detailsamplemaxerror /* 4 bytes */;
    short pad1 /* 2 bytes */;
    short pad2 /* 2 bytes */;
};

struct GameData {
    GameFraming framing /* 16 bytes */;
    short playerflag /* 2 bytes */;
    short xplay /* 2 bytes */;
    short yplay /* 2 bytes */;
    short freqplay /* 2 bytes */;
    short depth /* 2 bytes */;
    short attrib /* 2 bytes */;
    short rt1 /* 2 bytes */;
    short rt2 /* 2 bytes */;
    short aasamples /* 2 bytes */;
    short pad4[3] /* 6 bytes */;
    GameDome dome /* 24 bytes */;
    short stereoflag /* 2 bytes */;
    short stereomode /* 2 bytes */;
    float eyeseparation /* 4 bytes */;
    RecastData recastData /* 56 bytes */;
    float gravity /* 4 bytes */;
    float activityBoxRadius /* 4 bytes */;
    int flag /* 4 bytes */;
    short mode /* 2 bytes */;
    short matmode /* 2 bytes */;
    short occlusionRes /* 2 bytes */;
    short physicsEngine /* 2 bytes */;
    short exitkey /* 2 bytes */;
    short vsync /* 2 bytes */;
    short ticrate /* 2 bytes */;
    short maxlogicstep /* 2 bytes */;
    short physubstep /* 2 bytes */;
    short maxphystep /* 2 bytes */;
    short obstacleSimulation /* 2 bytes */;
    short raster_storage /* 2 bytes */;
    float levelHeight /* 4 bytes */;
    float deactivationtime /* 4 bytes */;
    float lineardeactthreshold /* 4 bytes */;
    float angulardeactthreshold /* 4 bytes */;
    float pad2 /* 4 bytes */;
};

struct TimeMarker {
    TimeMarker *next /* 8 bytes */;
    TimeMarker *prev /* 8 bytes */;
    int frame /* 4 bytes */;
    char name[64] /* 64 bytes */;
    int flag /* 4 bytes */;
    Object *camera /* 8 bytes */;
};

struct Paint {
    Brush *brush /* 8 bytes */;
    Palette *palette /* 8 bytes */;
    CurveMapping *cavity_curve /* 8 bytes */;
    void *paint_cursor /* 8 bytes */;
    char paint_cursor_col[4] /* 4 bytes */;
    int flags /* 4 bytes */;
    int num_input_samples /* 4 bytes */;
    int symmetry_flags /* 4 bytes */;
};

struct ImagePaintSettings {
    Paint paint /* 48 bytes */;
    short flag /* 2 bytes */;
    short missing_data /* 2 bytes */;
    short seam_bleed /* 2 bytes */;
    short normal_angle /* 2 bytes */;
    short screen_grab_size[2] /* 4 bytes */;
    int mode /* 4 bytes */;
    void *paintcursor /* 8 bytes */;
    Image *stencil /* 8 bytes */;
    Image *clone /* 8 bytes */;
    Image *canvas /* 8 bytes */;
    float stencil_col[3] /* 12 bytes */;
    float dither /* 4 bytes */;
};

struct ParticleBrushData {
    short size /* 2 bytes */;
    short step /* 2 bytes */;
    short invert /* 2 bytes */;
    short count /* 2 bytes */;
    int flag /* 4 bytes */;
    float strength /* 4 bytes */;
};

struct ParticleEditSettings {
    short flag /* 2 bytes */;
    short totrekey /* 2 bytes */;
    short totaddkey /* 2 bytes */;
    short brushtype /* 2 bytes */;
    ParticleBrushData brush[7] /* 112 bytes */;
    void *paintcursor /* 8 bytes */;
    float emitterdist /* 4 bytes */;
    float rt /* 4 bytes */;
    int selectmode /* 4 bytes */;
    int edittype /* 4 bytes */;
    int draw_step /* 4 bytes */;
    int fade_frames /* 4 bytes */;
    Scene *scene /* 8 bytes */;
    Object *object /* 8 bytes */;
    Object *shape_object /* 8 bytes */;
};

struct Sculpt {
    Paint paint /* 48 bytes */;
    int flags /* 4 bytes */;
    int radial_symm[3] /* 12 bytes */;
    float detail_size /* 4 bytes */;
    int symmetrize_direction /* 4 bytes */;
    float gravity_factor /* 4 bytes */;
    float constant_detail /* 4 bytes */;
    Object *gravity_object /* 8 bytes */;
    void *pad2 /* 8 bytes */;
};

struct UvSculpt {
    Paint paint /* 48 bytes */;
};

struct VPaint {
    Paint paint /* 48 bytes */;
    short flag /* 2 bytes */;
    short pad /* 2 bytes */;
    int tot /* 4 bytes */;
    int *vpaint_prev /* 8 bytes */;
    MDeformVert *wpaint_prev /* 8 bytes */;
    void *paintcursor /* 8 bytes */;
};

struct TransformOrientation {
    TransformOrientation *next /* 8 bytes */;
    TransformOrientation *prev /* 8 bytes */;
    char name[64] /* 64 bytes */;
    float mat[3][3] /* 36 bytes */;
    int pad /* 4 bytes */;
};

struct UnifiedPaintSettings {
    int size /* 4 bytes */;
    float unprojected_radius /* 4 bytes */;
    float alpha /* 4 bytes */;
    float weight /* 4 bytes */;
    float rgb[3] /* 12 bytes */;
    float secondary_rgb[3] /* 12 bytes */;
    int flag /* 4 bytes */;
    float last_rake[2] /* 8 bytes */;
    float last_rake_angle /* 4 bytes */;
    int last_stroke_valid /* 4 bytes */;
    float average_stroke_accum[3] /* 12 bytes */;
    int average_stroke_counter /* 4 bytes */;
    float brush_rotation /* 4 bytes */;
    float brush_rotation_sec /* 4 bytes */;
    int anchored_size /* 4 bytes */;
    float overlap_factor /* 4 bytes */;
    char draw_inverted /* 1 bytes */;
    char stroke_active /* 1 bytes */;
    char draw_anchored /* 1 bytes */;
    char do_linear_conversion /* 1 bytes */;
    float anchored_initial_mouse[2] /* 8 bytes */;
    float pixel_radius /* 4 bytes */;
    float size_pressure_value /* 4 bytes */;
    float tex_mouse[2] /* 8 bytes */;
    float mask_tex_mouse[2] /* 8 bytes */;
    void *colorspace /* 8 bytes */;
};

struct MeshStatVis {
    char type /* 1 bytes */;
    char _pad1[2] /* 2 bytes */;
    char overhang_axis /* 1 bytes */;
    float overhang_min /* 4 bytes */;
    float overhang_max /* 4 bytes */;
    float thickness_min /* 4 bytes */;
    float thickness_max /* 4 bytes */;
    char thickness_samples /* 1 bytes */;
    char _pad2[3] /* 3 bytes */;
    float distort_min /* 4 bytes */;
    float distort_max /* 4 bytes */;
    float sharp_min /* 4 bytes */;
    float sharp_max /* 4 bytes */;
};

struct ToolSettings {
    VPaint *vpaint /* 8 bytes */;
    VPaint *wpaint /* 8 bytes */;
    Sculpt *sculpt /* 8 bytes */;
    UvSculpt *uvsculpt /* 8 bytes */;
    float vgroup_weight /* 4 bytes */;
    float doublimit /* 4 bytes */;
    float normalsize /* 4 bytes */;
    short automerge /* 2 bytes */;
    short selectmode /* 2 bytes */;
    char unwrapper /* 1 bytes */;
    char uvcalc_flag /* 1 bytes */;
    char uv_flag /* 1 bytes */;
    char uv_selectmode /* 1 bytes */;
    float uvcalc_margin /* 4 bytes */;
    short autoik_chainlen /* 2 bytes */;
    char gpencil_flags /* 1 bytes */;
    char gpencil_src /* 1 bytes */;
    char pad[4] /* 4 bytes */;
    ImagePaintSettings imapaint /* 112 bytes */;
    ParticleEditSettings particle /* 176 bytes */;
    float proportional_size /* 4 bytes */;
    float select_thresh /* 4 bytes */;
    short autokey_mode /* 2 bytes */;
    short autokey_flag /* 2 bytes */;
    char multires_subdiv_type /* 1 bytes */;
    char pad3[1] /* 1 bytes */;
    short skgen_resolution /* 2 bytes */;
    float skgen_threshold_internal /* 4 bytes */;
    float skgen_threshold_external /* 4 bytes */;
    float skgen_length_ratio /* 4 bytes */;
    float skgen_length_limit /* 4 bytes */;
    float skgen_angle_limit /* 4 bytes */;
    float skgen_correlation_limit /* 4 bytes */;
    float skgen_symmetry_limit /* 4 bytes */;
    float skgen_retarget_angle_weight /* 4 bytes */;
    float skgen_retarget_length_weight /* 4 bytes */;
    float skgen_retarget_distance_weight /* 4 bytes */;
    short skgen_options /* 2 bytes */;
    char skgen_postpro /* 1 bytes */;
    char skgen_postpro_passes /* 1 bytes */;
    char skgen_subdivisions[3] /* 3 bytes */;
    char skgen_multi_level /* 1 bytes */;
    Object *skgen_template /* 8 bytes */;
    char bone_sketching /* 1 bytes */;
    char bone_sketching_convert /* 1 bytes */;
    char skgen_subdivision_number /* 1 bytes */;
    char skgen_retarget_options /* 1 bytes */;
    char skgen_retarget_roll /* 1 bytes */;
    char skgen_side_string[8] /* 8 bytes */;
    char skgen_num_string[8] /* 8 bytes */;
    char edge_mode /* 1 bytes */;
    char edge_mode_live_unwrap /* 1 bytes */;
    char snap_mode /* 1 bytes */;
    char snap_node_mode /* 1 bytes */;
    char snap_uv_mode /* 1 bytes */;
    short snap_flag /* 2 bytes */;
    short snap_target /* 2 bytes */;
    short proportional /* 2 bytes */;
    short prop_mode /* 2 bytes */;
    char proportional_objects /* 1 bytes */;
    char proportional_mask /* 1 bytes */;
    char auto_normalize /* 1 bytes */;
    char multipaint /* 1 bytes */;
    char weightuser /* 1 bytes */;
    char vgroupsubset /* 1 bytes */;
    int use_uv_sculpt /* 4 bytes */;
    int uv_sculpt_settings /* 4 bytes */;
    int uv_sculpt_tool /* 4 bytes */;
    int uv_relax_method /* 4 bytes */;
    short sculpt_paint_settings /* 2 bytes */;
    short pad5 /* 2 bytes */;
    int sculpt_paint_unified_size /* 4 bytes */;
    float sculpt_paint_unified_unprojected_radius /* 4 bytes */;
    float sculpt_paint_unified_alpha /* 4 bytes */;
    UnifiedPaintSettings unified_paint_settings /* 136 bytes */;
    MeshStatVis statvis /* 40 bytes */;
};

struct bStats {
    int totobj /* 4 bytes */;
    int totlamp /* 4 bytes */;
    int totobjsel /* 4 bytes */;
    int totcurve /* 4 bytes */;
    int totmesh /* 4 bytes */;
    int totarmature /* 4 bytes */;
    int totvert /* 4 bytes */;
    int totface /* 4 bytes */;
};

struct UnitSettings {
    float scale_length /* 4 bytes */;
    char system /* 1 bytes */;
    char system_rotation /* 1 bytes */;
    short flag /* 2 bytes */;
};

struct PhysicsSettings {
    float gravity[3] /* 12 bytes */;
    int flag /* 4 bytes */;
    int quick_cache_step /* 4 bytes */;
    int rt /* 4 bytes */;
};

struct DisplaySafeAreas {
    float title[2] /* 8 bytes */;
    float action[2] /* 8 bytes */;
    float title_center[2] /* 8 bytes */;
    float action_center[2] /* 8 bytes */;
};

struct Scene {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
    Object *camera /* 8 bytes */;
    World *world /* 8 bytes */;
    Scene *set /* 8 bytes */;
    ListBase base /* 16 bytes */;
    Base *basact /* 8 bytes */;
    Object *obedit /* 8 bytes */;
    float cursor[3] /* 12 bytes */;
    float twcent[3] /* 12 bytes */;
    float twmin[3] /* 12 bytes */;
    float twmax[3] /* 12 bytes */;
    int lay /* 4 bytes */;
    int layact /* 4 bytes */;
    int lay_updated /* 4 bytes */;
    short flag /* 2 bytes */;
    char use_nodes /* 1 bytes */;
    char pad[1] /* 1 bytes */;
    bNodeTree *nodetree /* 8 bytes */;
    Editing *ed /* 8 bytes */;
    ToolSettings *toolsettings /* 8 bytes */;
    void *stats /* 8 bytes */;
    DisplaySafeAreas safe_areas /* 32 bytes */;
    RenderData r /* 3984 bytes */;
    AudioData audio /* 32 bytes */;
    ListBase markers /* 16 bytes */;
    ListBase transform_spaces /* 16 bytes */;
    void *sound_scene /* 8 bytes */;
    void *sound_scene_handle /* 8 bytes */;
    void *sound_scrub_handle /* 8 bytes */;
    void *speaker_handles /* 8 bytes */;
    void *fps_info /* 8 bytes */;
    void *theDag /* 8 bytes */;
    short dagflags /* 2 bytes */;
    short recalc /* 2 bytes */;
    int active_keyingset /* 4 bytes */;
    ListBase keyingsets /* 16 bytes */;
    GameFraming framing /* 16 bytes */;
    GameData gm /* 184 bytes */;
    UnitSettings unit /* 8 bytes */;
    bGPdata *gpd /* 8 bytes */;
    PhysicsSettings physics_settings /* 24 bytes */;
    MovieClip *clip /* 8 bytes */;
    uint64_t customdata_mask /* 8 bytes */;
    uint64_t customdata_mask_modal /* 8 bytes */;
    ColorManagedViewSettings view_settings /* 160 bytes */;
    ColorManagedDisplaySettings display_settings /* 64 bytes */;
    ColorManagedColorspaceSettings sequencer_colorspace_settings /* 64 bytes */;
    RigidBodyWorld *rigidbody_world /* 8 bytes */;
};

struct MovieClipUser {
    int framenr /* 4 bytes */;
    short render_size /* 2 bytes */;
    short render_flag /* 2 bytes */;
};

struct BGpic {
    BGpic *next /* 8 bytes */;
    BGpic *prev /* 8 bytes */;
    Image *ima /* 8 bytes */;
    ImageUser iuser /* 40 bytes */;
    MovieClip *clip /* 8 bytes */;
    MovieClipUser cuser /* 8 bytes */;
    float xof /* 4 bytes */;
    float yof /* 4 bytes */;
    float size /* 4 bytes */;
    float blend /* 4 bytes */;
    float rotation /* 4 bytes */;
    short view /* 2 bytes */;
    short flag /* 2 bytes */;
    short source /* 2 bytes */;
    char pad[6] /* 6 bytes */;
};

struct RegionView3D {
    float winmat[4][4] /* 64 bytes */;
    float viewmat[4][4] /* 64 bytes */;
    float viewinv[4][4] /* 64 bytes */;
    float persmat[4][4] /* 64 bytes */;
    float persinv[4][4] /* 64 bytes */;
    float viewcamtexcofac[4] /* 16 bytes */;
    float viewmatob[4][4] /* 64 bytes */;
    float persmatob[4][4] /* 64 bytes */;
    float clip[6][4] /* 96 bytes */;
    float clip_local[6][4] /* 96 bytes */;
    BoundBox *clipbb /* 8 bytes */;
    RegionView3D *localvd /* 8 bytes */;
    void *render_engine /* 8 bytes */;
    void *depths /* 8 bytes */;
    void *gpuoffscreen /* 8 bytes */;
    void *sms /* 8 bytes */;
    void *smooth_timer /* 8 bytes */;
    float twmat[4][4] /* 64 bytes */;
    float viewquat[4] /* 16 bytes */;
    float dist /* 4 bytes */;
    float camdx /* 4 bytes */;
    float camdy /* 4 bytes */;
    float pixsize /* 4 bytes */;
    float ofs[3] /* 12 bytes */;
    float camzoom /* 4 bytes */;
    char is_persp /* 1 bytes */;
    char persp /* 1 bytes */;
    char view /* 1 bytes */;
    char viewlock /* 1 bytes */;
    char viewlock_quad /* 1 bytes */;
    char pad[3] /* 3 bytes */;
    float ofs_lock[2] /* 8 bytes */;
    short twdrawflag /* 2 bytes */;
    short rflag /* 2 bytes */;
    float lviewquat[4] /* 16 bytes */;
    short lpersp /* 2 bytes */;
    short lview /* 2 bytes */;
    float gridview /* 4 bytes */;
    float tw_idot[3] /* 12 bytes */;
    float rot_angle /* 4 bytes */;
    float rot_axis[3] /* 12 bytes */;
    void *compositor /* 8 bytes */;
};

struct View3D {
    SpaceLink *next /* 8 bytes */;
    SpaceLink *prev /* 8 bytes */;
    ListBase regionbase /* 16 bytes */;
    int spacetype /* 4 bytes */;
    float blockscale /* 4 bytes */;
    short blockhandler[8] /* 16 bytes */;
    float viewquat[4] /* 16 bytes */;
    float dist /* 4 bytes */;
    float bundle_size /* 4 bytes */;
    char bundle_drawtype /* 1 bytes */;
    char pad[3] /* 3 bytes */;
    int lay_prev /* 4 bytes */;
    int lay_used /* 4 bytes */;
    short persp /* 2 bytes */;
    short view /* 2 bytes */;
    Object *camera /* 8 bytes */;
    Object *ob_centre /* 8 bytes */;
    rctf render_border /* 16 bytes */;
    ListBase bgpicbase /* 16 bytes */;
    BGpic *bgpic /* 8 bytes */;
    View3D *localvd /* 8 bytes */;
    char ob_centre_bone[64] /* 64 bytes */;
    int lay /* 4 bytes */;
    int layact /* 4 bytes */;
    short drawtype /* 2 bytes */;
    short ob_centre_cursor /* 2 bytes */;
    short scenelock /* 2 bytes */;
    short around /* 2 bytes */;
    short flag /* 2 bytes */;
    short flag2 /* 2 bytes */;
    float lens /* 4 bytes */;
    float grid /* 4 bytes */;
    float near /* 4 bytes */;
    float far /* 4 bytes */;
    float ofs[3] /* 12 bytes */;
    float cursor[3] /* 12 bytes */;
    short matcap_icon /* 2 bytes */;
    short gridlines /* 2 bytes */;
    short gridsubdiv /* 2 bytes */;
    char gridflag /* 1 bytes */;
    char twtype /* 1 bytes */;
    char twmode /* 1 bytes */;
    char twflag /* 1 bytes */;
    short flag3 /* 2 bytes */;
    ListBase afterdraw_transp /* 16 bytes */;
    ListBase afterdraw_xray /* 16 bytes */;
    ListBase afterdraw_xraytransp /* 16 bytes */;
    char zbuf /* 1 bytes */;
    char transp /* 1 bytes */;
    char xray /* 1 bytes */;
    char pad3[5] /* 5 bytes */;
    GPUFXSettings fx_settings /* 24 bytes */;
    void *properties_storage /* 8 bytes */;
    Material *defmaterial /* 8 bytes */;
    bGPdata *gpd /* 8 bytes */;
};

struct View2D {
    rctf tot /* 16 bytes */;
    rctf cur /* 16 bytes */;
    rcti vert /* 16 bytes */;
    rcti hor /* 16 bytes */;
    rcti mask /* 16 bytes */;
    float min[2] /* 8 bytes */;
    float max[2] /* 8 bytes */;
    float minzoom /* 4 bytes */;
    float maxzoom /* 4 bytes */;
    short scroll /* 2 bytes */;
    short scroll_ui /* 2 bytes */;
    short keeptot /* 2 bytes */;
    short keepzoom /* 2 bytes */;
    short keepofs /* 2 bytes */;
    short flag /* 2 bytes */;
    short align /* 2 bytes */;
    short winx /* 2 bytes */;
    short winy /* 2 bytes */;
    short oldwinx /* 2 bytes */;
    short oldwiny /* 2 bytes */;
    short around /* 2 bytes */;
    float *tab_offset /* 8 bytes */;
    int tab_num /* 4 bytes */;
    int tab_cur /* 4 bytes */;
    void *sms /* 8 bytes */;
    void *smooth_timer /* 8 bytes */;
};

struct SpaceLink {
    SpaceLink *next /* 8 bytes */;
    SpaceLink *prev /* 8 bytes */;
    ListBase regionbase /* 16 bytes */;
    int spacetype /* 4 bytes */;
    float blockscale /* 4 bytes */;
    short blockhandler[8] /* 16 bytes */;
};

struct SpaceInfo {
    SpaceLink *next /* 8 bytes */;
    SpaceLink *prev /* 8 bytes */;
    ListBase regionbase /* 16 bytes */;
    int spacetype /* 4 bytes */;
    float blockscale /* 4 bytes */;
    short blockhandler[8] /* 16 bytes */;
    char rpt_mask /* 1 bytes */;
    char pad[7] /* 7 bytes */;
};

struct SpaceButs {
    SpaceLink *next /* 8 bytes */;
    SpaceLink *prev /* 8 bytes */;
    ListBase regionbase /* 16 bytes */;
    int spacetype /* 4 bytes */;
    float blockscale /* 4 bytes */;
    short blockhandler[8] /* 16 bytes */;
    View2D v2d /* 160 bytes */;
    short mainb /* 2 bytes */;
    short mainbo /* 2 bytes */;
    short mainbuser /* 2 bytes */;
    short re_align /* 2 bytes */;
    short align /* 2 bytes */;
    short preview /* 2 bytes */;
    short texture_context /* 2 bytes */;
    short texture_context_prev /* 2 bytes */;
    char flag /* 1 bytes */;
    char pad[7] /* 7 bytes */;
    void *path /* 8 bytes */;
    int pathflag /* 4 bytes */;
    int dataicon /* 4 bytes */;
    ID *pinid /* 8 bytes */;
    void *texuser /* 8 bytes */;
};

struct TreeStoreElem {
    short type /* 2 bytes */;
    short nr /* 2 bytes */;
    short flag /* 2 bytes */;
    short used /* 2 bytes */;
    ID *id /* 8 bytes */;
};

struct SpaceOops {
    SpaceLink *next /* 8 bytes */;
    SpaceLink *prev /* 8 bytes */;
    ListBase regionbase /* 16 bytes */;
    int spacetype /* 4 bytes */;
    float blockscale /* 4 bytes */;
    short blockhandler[8] /* 16 bytes */;
    View2D v2d /* 160 bytes */;
    ListBase tree /* 16 bytes */;
    void *treestore /* 8 bytes */;
    char search_string[32] /* 32 bytes */;
    TreeStoreElem search_tse /* 16 bytes */;
    short flag /* 2 bytes */;
    short outlinevis /* 2 bytes */;
    short storeflag /* 2 bytes */;
    short search_flags /* 2 bytes */;
    void *treehash /* 8 bytes */;
};

struct SpaceIpo {
    SpaceLink *next /* 8 bytes */;
    SpaceLink *prev /* 8 bytes */;
    ListBase regionbase /* 16 bytes */;
    int spacetype /* 4 bytes */;
    float blockscale /* 4 bytes */;
    short blockhandler[8] /* 16 bytes */;
    View2D v2d /* 160 bytes */;
    bDopeSheet *ads /* 8 bytes */;
    ListBase ghostCurves /* 16 bytes */;
    short mode /* 2 bytes */;
    short autosnap /* 2 bytes */;
    int flag /* 4 bytes */;
    float cursorVal /* 4 bytes */;
    int around /* 4 bytes */;
};

struct SpaceNla {
    SpaceLink *next /* 8 bytes */;
    SpaceLink *prev /* 8 bytes */;
    ListBase regionbase /* 16 bytes */;
    int spacetype /* 4 bytes */;
    float blockscale /* 4 bytes */;
    short blockhandler[8] /* 16 bytes */;
    short autosnap /* 2 bytes */;
    short flag /* 2 bytes */;
    int pad /* 4 bytes */;
    bDopeSheet *ads /* 8 bytes */;
    View2D v2d /* 160 bytes */;
};

struct SpaceTimeCache {
    SpaceTimeCache *next /* 8 bytes */;
    SpaceTimeCache *prev /* 8 bytes */;
    float *array /* 8 bytes */;
};

struct SpaceTime {
    SpaceLink *next /* 8 bytes */;
    SpaceLink *prev /* 8 bytes */;
    ListBase regionbase /* 16 bytes */;
    int spacetype /* 4 bytes */;
    float blockscale /* 4 bytes */;
    View2D v2d /* 160 bytes */;
    ListBase caches /* 16 bytes */;
    int cache_display /* 4 bytes */;
    int flag /* 4 bytes */;
};

struct SequencerScopes {
    void *reference_ibuf /* 8 bytes */;
    void *zebra_ibuf /* 8 bytes */;
    void *waveform_ibuf /* 8 bytes */;
    void *sep_waveform_ibuf /* 8 bytes */;
    void *vector_ibuf /* 8 bytes */;
    void *histogram_ibuf /* 8 bytes */;
};

struct SpaceSeq {
    SpaceLink *next /* 8 bytes */;
    SpaceLink *prev /* 8 bytes */;
    ListBase regionbase /* 16 bytes */;
    int spacetype /* 4 bytes */;
    float blockscale /* 4 bytes */;
    short blockhandler[8] /* 16 bytes */;
    View2D v2d /* 160 bytes */;
    float xof /* 4 bytes */;
    float yof /* 4 bytes */;
    short mainb /* 2 bytes */;
    short render_size /* 2 bytes */;
    short chanshown /* 2 bytes */;
    short zebra /* 2 bytes */;
    int flag /* 4 bytes */;
    float zoom /* 4 bytes */;
    int view /* 4 bytes */;
    int overlay_type /* 4 bytes */;
    int draw_flag /* 4 bytes */;
    int pad /* 4 bytes */;
    bGPdata *gpd /* 8 bytes */;
    SequencerScopes scopes /* 48 bytes */;
};

struct MaskSpaceInfo {
    Mask *mask /* 8 bytes */;
    char draw_flag /* 1 bytes */;
    char draw_type /* 1 bytes */;
    char overlay_mode /* 1 bytes */;
    char pad3[5] /* 5 bytes */;
};

struct FileSelectParams {
    char title[96] /* 96 bytes */;
    char dir[1090] /* 1090 bytes */;
    char pad_c1[2] /* 2 bytes */;
    char file[256] /* 256 bytes */;
    char renamefile[256] /* 256 bytes */;
    char renameedit[256] /* 256 bytes */;
    char filter_glob[64] /* 64 bytes */;
    char filter_search[64] /* 64 bytes */;
    int active_file /* 4 bytes */;
    int sel_first /* 4 bytes */;
    int sel_last /* 4 bytes */;
    short type /* 2 bytes */;
    short flag /* 2 bytes */;
    short sort /* 2 bytes */;
    short display /* 2 bytes */;
    short filter /* 2 bytes */;
    short f_fp /* 2 bytes */;
    char fp_str[8] /* 8 bytes */;
};

struct SpaceFile {
    SpaceLink *next /* 8 bytes */;
    SpaceLink *prev /* 8 bytes */;
    ListBase regionbase /* 16 bytes */;
    int spacetype /* 4 bytes */;
    int scroll_offset /* 4 bytes */;
    FileSelectParams *params /* 8 bytes */;
    void *files /* 8 bytes */;
    ListBase *folders_prev /* 8 bytes */;
    ListBase *folders_next /* 8 bytes */;
    wmOperator *op /* 8 bytes */;
    void *smoothscroll_timer /* 8 bytes */;
    void *layout /* 8 bytes */;
    short recentnr /* 2 bytes */;
    short bookmarknr /* 2 bytes */;
    short systemnr /* 2 bytes */;
    short system_bookmarknr /* 2 bytes */;
};

struct FSMenuEntry {
    FSMenuEntry *next /* 8 bytes */;
    char *path /* 8 bytes */;
    char name[256] /* 256 bytes */;
    short save /* 2 bytes */;
    short valid /* 2 bytes */;
    short pad[2] /* 4 bytes */;
};

struct Histogram {
    int channels /* 4 bytes */;
    int x_resolution /* 4 bytes */;
    float data_luma[256] /* 1024 bytes */;
    float data_r[256] /* 1024 bytes */;
    float data_g[256] /* 1024 bytes */;
    float data_b[256] /* 1024 bytes */;
    float data_a[256] /* 1024 bytes */;
    float xmax /* 4 bytes */;
    float ymax /* 4 bytes */;
    short mode /* 2 bytes */;
    short flag /* 2 bytes */;
    int height /* 4 bytes */;
    float co[2][2] /* 16 bytes */;
};

struct Scopes {
    int ok /* 4 bytes */;
    int sample_full /* 4 bytes */;
    int sample_lines /* 4 bytes */;
    float accuracy /* 4 bytes */;
    int wavefrm_mode /* 4 bytes */;
    float wavefrm_alpha /* 4 bytes */;
    float wavefrm_yfac /* 4 bytes */;
    int wavefrm_height /* 4 bytes */;
    float vecscope_alpha /* 4 bytes */;
    int vecscope_height /* 4 bytes */;
    float minmax[3][2] /* 24 bytes */;
    Histogram hist /* 5160 bytes */;
    float *waveform_1 /* 8 bytes */;
    float *waveform_2 /* 8 bytes */;
    float *waveform_3 /* 8 bytes */;
    float *vecscope /* 8 bytes */;
    int waveform_tot /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct SpaceImage {
    SpaceLink *next /* 8 bytes */;
    SpaceLink *prev /* 8 bytes */;
    ListBase regionbase /* 16 bytes */;
    int spacetype /* 4 bytes */;
    int flag /* 4 bytes */;
    Image *image /* 8 bytes */;
    ImageUser iuser /* 40 bytes */;
    CurveMapping *cumap /* 8 bytes */;
    Scopes scopes /* 5264 bytes */;
    Histogram sample_line_hist /* 5160 bytes */;
    bGPdata *gpd /* 8 bytes */;
    float cursor[2] /* 8 bytes */;
    float xof /* 4 bytes */;
    float yof /* 4 bytes */;
    float zoom /* 4 bytes */;
    float centx /* 4 bytes */;
    float centy /* 4 bytes */;
    char mode /* 1 bytes */;
    char pin /* 1 bytes */;
    short pad /* 2 bytes */;
    short curtile /* 2 bytes */;
    short lock /* 2 bytes */;
    char dt_uv /* 1 bytes */;
    char sticky /* 1 bytes */;
    char dt_uvstretch /* 1 bytes */;
    char around /* 1 bytes */;
    MaskSpaceInfo mask_info /* 16 bytes */;
};

struct SpaceText {
    SpaceLink *next /* 8 bytes */;
    SpaceLink *prev /* 8 bytes */;
    ListBase regionbase /* 16 bytes */;
    int spacetype /* 4 bytes */;
    float blockscale /* 4 bytes */;
    short blockhandler[8] /* 16 bytes */;
    Text *text /* 8 bytes */;
    int top /* 4 bytes */;
    int viewlines /* 4 bytes */;
    short flags /* 2 bytes */;
    short menunr /* 2 bytes */;
    short lheight /* 2 bytes */;
    char cwidth /* 1 bytes */;
    char linenrs_tot /* 1 bytes */;
    int left /* 4 bytes */;
    int showlinenrs /* 4 bytes */;
    int tabnumber /* 4 bytes */;
    short showsyntax /* 2 bytes */;
    short line_hlight /* 2 bytes */;
    short overwrite /* 2 bytes */;
    short live_edit /* 2 bytes */;
    float pix_per_line /* 4 bytes */;
    rcti txtscroll /* 16 bytes */;
    rcti txtbar /* 16 bytes */;
    int wordwrap /* 4 bytes */;
    int doplugins /* 4 bytes */;
    char findstr[256] /* 256 bytes */;
    char replacestr[256] /* 256 bytes */;
    short margin_column /* 2 bytes */;
    short lheight_dpi /* 2 bytes */;
    char pad[4] /* 4 bytes */;
    void *drawcache /* 8 bytes */;
    float scroll_accum[2] /* 8 bytes */;
};

struct Script {
    ID id /* 120 bytes */;
    void *py_draw /* 8 bytes */;
    void *py_event /* 8 bytes */;
    void *py_button /* 8 bytes */;
    void *py_browsercallback /* 8 bytes */;
    void *py_globaldict /* 8 bytes */;
    int flags /* 4 bytes */;
    int lastspace /* 4 bytes */;
    char scriptname[1024] /* 1024 bytes */;
    char scriptarg[256] /* 256 bytes */;
};

struct SpaceScript {
    SpaceLink *next /* 8 bytes */;
    SpaceLink *prev /* 8 bytes */;
    ListBase regionbase /* 16 bytes */;
    int spacetype /* 4 bytes */;
    float blockscale /* 4 bytes */;
    Script *script /* 8 bytes */;
    short flags /* 2 bytes */;
    short menunr /* 2 bytes */;
    int pad1 /* 4 bytes */;
    void *but_refs /* 8 bytes */;
};

struct bNodeInstanceKey {
    int value /* 4 bytes */;
};

struct bNodeTreePath {
    bNodeTreePath *next /* 8 bytes */;
    bNodeTreePath *prev /* 8 bytes */;
    bNodeTree *nodetree /* 8 bytes */;
    bNodeInstanceKey parent_key /* 4 bytes */;
    int pad /* 4 bytes */;
    float view_center[2] /* 8 bytes */;
    char node_name[64] /* 64 bytes */;
};

struct SpaceNode {
    SpaceLink *next /* 8 bytes */;
    SpaceLink *prev /* 8 bytes */;
    ListBase regionbase /* 16 bytes */;
    int spacetype /* 4 bytes */;
    float blockscale /* 4 bytes */;
    short blockhandler[8] /* 16 bytes */;
    View2D v2d /* 160 bytes */;
    ID *id /* 8 bytes */;
    ID *from /* 8 bytes */;
    short flag /* 2 bytes */;
    short pad1 /* 2 bytes */;
    float aspect /* 4 bytes */;
    float pad2 /* 4 bytes */;
    float xof /* 4 bytes */;
    float yof /* 4 bytes */;
    float zoom /* 4 bytes */;
    float cursor[2] /* 8 bytes */;
    ListBase treepath /* 16 bytes */;
    bNodeTree *nodetree /* 8 bytes */;
    bNodeTree *edittree /* 8 bytes */;
    char tree_idname[64] /* 64 bytes */;
    int treetype /* 4 bytes */;
    int pad3 /* 4 bytes */;
    short texfrom /* 2 bytes */;
    short shaderfrom /* 2 bytes */;
    short recalc /* 2 bytes */;
    short pad4 /* 2 bytes */;
    ListBase linkdrag /* 16 bytes */;
    bGPdata *gpd /* 8 bytes */;
};

struct SpaceLogic {
    SpaceLink *next /* 8 bytes */;
    SpaceLink *prev /* 8 bytes */;
    ListBase regionbase /* 16 bytes */;
    int spacetype /* 4 bytes */;
    float blockscale /* 4 bytes */;
    short blockhandler[8] /* 16 bytes */;
    short flag /* 2 bytes */;
    short scaflag /* 2 bytes */;
    int pad /* 4 bytes */;
    bGPdata *gpd /* 8 bytes */;
};

struct ConsoleLine {
    ConsoleLine *next /* 8 bytes */;
    ConsoleLine *prev /* 8 bytes */;
    int len_alloc /* 4 bytes */;
    int len /* 4 bytes */;
    char *line /* 8 bytes */;
    int cursor /* 4 bytes */;
    int type /* 4 bytes */;
};

struct SpaceConsole {
    SpaceLink *next /* 8 bytes */;
    SpaceLink *prev /* 8 bytes */;
    ListBase regionbase /* 16 bytes */;
    int spacetype /* 4 bytes */;
    float blockscale /* 4 bytes */;
    short blockhandler[8] /* 16 bytes */;
    int lheight /* 4 bytes */;
    int pad /* 4 bytes */;
    ListBase scrollback /* 16 bytes */;
    ListBase history /* 16 bytes */;
    char prompt[256] /* 256 bytes */;
    char language[32] /* 32 bytes */;
    int sel_start /* 4 bytes */;
    int sel_end /* 4 bytes */;
};

struct SpaceUserPref {
    SpaceLink *next /* 8 bytes */;
    SpaceLink *prev /* 8 bytes */;
    ListBase regionbase /* 16 bytes */;
    int spacetype /* 4 bytes */;
    char pad[3] /* 3 bytes */;
    char filter_type /* 1 bytes */;
    char filter[64] /* 64 bytes */;
};

struct MovieTrackingMarker {
    float pos[2] /* 8 bytes */;
    float pattern_corners[4][2] /* 32 bytes */;
    float search_min[2] /* 8 bytes */;
    float search_max[2] /* 8 bytes */;
    int framenr /* 4 bytes */;
    int flag /* 4 bytes */;
};

struct MovieClipScopes {
    short ok /* 2 bytes */;
    short use_track_mask /* 2 bytes */;
    int track_preview_height /* 4 bytes */;
    int frame_width /* 4 bytes */;
    int frame_height /* 4 bytes */;
    MovieTrackingMarker undist_marker /* 64 bytes */;
    void *track_search /* 8 bytes */;
    void *track_preview /* 8 bytes */;
    float track_pos[2] /* 8 bytes */;
    short track_disabled /* 2 bytes */;
    short track_locked /* 2 bytes */;
    int framenr /* 4 bytes */;
    MovieTrackingTrack *track /* 8 bytes */;
    MovieTrackingMarker *marker /* 8 bytes */;
    float slide_scale[2] /* 8 bytes */;
};

struct SpaceClip {
    SpaceLink *next /* 8 bytes */;
    SpaceLink *prev /* 8 bytes */;
    ListBase regionbase /* 16 bytes */;
    int spacetype /* 4 bytes */;
    float xof /* 4 bytes */;
    float yof /* 4 bytes */;
    float xlockof /* 4 bytes */;
    float ylockof /* 4 bytes */;
    float zoom /* 4 bytes */;
    MovieClipUser user /* 8 bytes */;
    MovieClip *clip /* 8 bytes */;
    MovieClipScopes scopes /* 136 bytes */;
    int flag /* 4 bytes */;
    short mode /* 2 bytes */;
    short view /* 2 bytes */;
    int path_length /* 4 bytes */;
    float loc[2] /* 8 bytes */;
    float scale /* 4 bytes */;
    float angle /* 4 bytes */;
    int pad /* 4 bytes */;
    float stabmat[4][4] /* 64 bytes */;
    float unistabmat[4][4] /* 64 bytes */;
    int postproc_flag /* 4 bytes */;
    short gpencil_src /* 2 bytes */;
    short pad2 /* 2 bytes */;
    int around /* 4 bytes */;
    int pad4 /* 4 bytes */;
    float cursor[2] /* 8 bytes */;
    MaskSpaceInfo mask_info /* 16 bytes */;
};

struct uiFont {
    uiFont *next /* 8 bytes */;
    uiFont *prev /* 8 bytes */;
    char filename[1024] /* 1024 bytes */;
    short blf_id /* 2 bytes */;
    short uifont_id /* 2 bytes */;
    short r_to_l /* 2 bytes */;
    short hinting /* 2 bytes */;
};

struct uiFontStyle {
    short uifont_id /* 2 bytes */;
    short points /* 2 bytes */;
    short kerning /* 2 bytes */;
    char pad[6] /* 6 bytes */;
    short italic /* 2 bytes */;
    short bold /* 2 bytes */;
    short shadow /* 2 bytes */;
    short shadx /* 2 bytes */;
    short shady /* 2 bytes */;
    short align /* 2 bytes */;
    float shadowalpha /* 4 bytes */;
    float shadowcolor /* 4 bytes */;
};

struct uiStyle {
    uiStyle *next /* 8 bytes */;
    uiStyle *prev /* 8 bytes */;
    char name[64] /* 64 bytes */;
    uiFontStyle paneltitle /* 32 bytes */;
    uiFontStyle grouplabel /* 32 bytes */;
    uiFontStyle widgetlabel /* 32 bytes */;
    uiFontStyle widget /* 32 bytes */;
    float panelzoom /* 4 bytes */;
    short minlabelchars /* 2 bytes */;
    short minwidgetchars /* 2 bytes */;
    short columnspace /* 2 bytes */;
    short templatespace /* 2 bytes */;
    short boxspace /* 2 bytes */;
    short buttonspacex /* 2 bytes */;
    short buttonspacey /* 2 bytes */;
    short panelspace /* 2 bytes */;
    short panelouter /* 2 bytes */;
    short pad /* 2 bytes */;
};

struct uiWidgetColors {
    char outline[4] /* 4 bytes */;
    char inner[4] /* 4 bytes */;
    char inner_sel[4] /* 4 bytes */;
    char item[4] /* 4 bytes */;
    char text[4] /* 4 bytes */;
    char text_sel[4] /* 4 bytes */;
    short shaded /* 2 bytes */;
    short shadetop /* 2 bytes */;
    short shadedown /* 2 bytes */;
    short alpha_check /* 2 bytes */;
};

struct uiWidgetStateColors {
    char inner_anim[4] /* 4 bytes */;
    char inner_anim_sel[4] /* 4 bytes */;
    char inner_key[4] /* 4 bytes */;
    char inner_key_sel[4] /* 4 bytes */;
    char inner_driven[4] /* 4 bytes */;
    char inner_driven_sel[4] /* 4 bytes */;
    float blend /* 4 bytes */;
    float pad /* 4 bytes */;
};

struct uiPanelColors {
    char header[4] /* 4 bytes */;
    char back[4] /* 4 bytes */;
    short show_header /* 2 bytes */;
    short show_back /* 2 bytes */;
    int pad /* 4 bytes */;
};

struct uiGradientColors {
    char gradient[4] /* 4 bytes */;
    char high_gradient[4] /* 4 bytes */;
    int show_grad /* 4 bytes */;
    int pad2 /* 4 bytes */;
};

struct ThemeUI {
    uiWidgetColors wcol_regular /* 32 bytes */;
    uiWidgetColors wcol_tool /* 32 bytes */;
    uiWidgetColors wcol_text /* 32 bytes */;
    uiWidgetColors wcol_radio /* 32 bytes */;
    uiWidgetColors wcol_option /* 32 bytes */;
    uiWidgetColors wcol_toggle /* 32 bytes */;
    uiWidgetColors wcol_num /* 32 bytes */;
    uiWidgetColors wcol_numslider /* 32 bytes */;
    uiWidgetColors wcol_menu /* 32 bytes */;
    uiWidgetColors wcol_pulldown /* 32 bytes */;
    uiWidgetColors wcol_menu_back /* 32 bytes */;
    uiWidgetColors wcol_menu_item /* 32 bytes */;
    uiWidgetColors wcol_tooltip /* 32 bytes */;
    uiWidgetColors wcol_box /* 32 bytes */;
    uiWidgetColors wcol_scroll /* 32 bytes */;
    uiWidgetColors wcol_progress /* 32 bytes */;
    uiWidgetColors wcol_list_item /* 32 bytes */;
    uiWidgetColors wcol_pie_menu /* 32 bytes */;
    uiWidgetStateColors wcol_state /* 32 bytes */;
    uiPanelColors panel /* 16 bytes */;
    char widget_emboss[4] /* 4 bytes */;
    float menu_shadow_fac /* 4 bytes */;
    short menu_shadow_width /* 2 bytes */;
    short pad[3] /* 6 bytes */;
    char iconfile[256] /* 256 bytes */;
    float icon_alpha /* 4 bytes */;
    char xaxis[4] /* 4 bytes */;
    char yaxis[4] /* 4 bytes */;
    char zaxis[4] /* 4 bytes */;
};

struct ThemeSpace {
    char back[4] /* 4 bytes */;
    char title[4] /* 4 bytes */;
    char text[4] /* 4 bytes */;
    char text_hi[4] /* 4 bytes */;
    char header[4] /* 4 bytes */;
    char header_title[4] /* 4 bytes */;
    char header_text[4] /* 4 bytes */;
    char header_text_hi[4] /* 4 bytes */;
    char tab_active[4] /* 4 bytes */;
    char tab_inactive[4] /* 4 bytes */;
    char tab_back[4] /* 4 bytes */;
    char tab_outline[4] /* 4 bytes */;
    char button[4] /* 4 bytes */;
    char button_title[4] /* 4 bytes */;
    char button_text[4] /* 4 bytes */;
    char button_text_hi[4] /* 4 bytes */;
    char list[4] /* 4 bytes */;
    char list_title[4] /* 4 bytes */;
    char list_text[4] /* 4 bytes */;
    char list_text_hi[4] /* 4 bytes */;
    uiPanelColors panelcolors /* 16 bytes */;
    uiGradientColors gradients /* 16 bytes */;
    char shade1[4] /* 4 bytes */;
    char shade2[4] /* 4 bytes */;
    char hilite[4] /* 4 bytes */;
    char grid[4] /* 4 bytes */;
    char view_overlay[4] /* 4 bytes */;
    char wire[4] /* 4 bytes */;
    char wire_edit[4] /* 4 bytes */;
    char select[4] /* 4 bytes */;
    char lamp[4] /* 4 bytes */;
    char speaker[4] /* 4 bytes */;
    char empty[4] /* 4 bytes */;
    char camera[4] /* 4 bytes */;
    char active[4] /* 4 bytes */;
    char group[4] /* 4 bytes */;
    char group_active[4] /* 4 bytes */;
    char transform[4] /* 4 bytes */;
    char vertex[4] /* 4 bytes */;
    char vertex_select[4] /* 4 bytes */;
    char vertex_unreferenced[4] /* 4 bytes */;
    char edge[4] /* 4 bytes */;
    char edge_select[4] /* 4 bytes */;
    char edge_seam[4] /* 4 bytes */;
    char edge_sharp[4] /* 4 bytes */;
    char edge_facesel[4] /* 4 bytes */;
    char edge_crease[4] /* 4 bytes */;
    char face[4] /* 4 bytes */;
    char face_select[4] /* 4 bytes */;
    char face_dot[4] /* 4 bytes */;
    char extra_edge_len[4] /* 4 bytes */;
    char extra_edge_angle[4] /* 4 bytes */;
    char extra_face_angle[4] /* 4 bytes */;
    char extra_face_area[4] /* 4 bytes */;
    char normal[4] /* 4 bytes */;
    char vertex_normal[4] /* 4 bytes */;
    char loop_normal[4] /* 4 bytes */;
    char bone_solid[4] /* 4 bytes */;
    char bone_pose[4] /* 4 bytes */;
    char bone_pose_active[4] /* 4 bytes */;
    char strip[4] /* 4 bytes */;
    char strip_select[4] /* 4 bytes */;
    char cframe[4] /* 4 bytes */;
    char time_keyframe[4] /* 4 bytes */;
    char time_gp_keyframe[4] /* 4 bytes */;
    char freestyle_edge_mark[4] /* 4 bytes */;
    char freestyle_face_mark[4] /* 4 bytes */;
    char nurb_uline[4] /* 4 bytes */;
    char nurb_vline[4] /* 4 bytes */;
    char act_spline[4] /* 4 bytes */;
    char nurb_sel_uline[4] /* 4 bytes */;
    char nurb_sel_vline[4] /* 4 bytes */;
    char lastsel_point[4] /* 4 bytes */;
    char handle_free[4] /* 4 bytes */;
    char handle_auto[4] /* 4 bytes */;
    char handle_vect[4] /* 4 bytes */;
    char handle_align[4] /* 4 bytes */;
    char handle_auto_clamped[4] /* 4 bytes */;
    char handle_sel_free[4] /* 4 bytes */;
    char handle_sel_auto[4] /* 4 bytes */;
    char handle_sel_vect[4] /* 4 bytes */;
    char handle_sel_align[4] /* 4 bytes */;
    char handle_sel_auto_clamped[4] /* 4 bytes */;
    char ds_channel[4] /* 4 bytes */;
    char ds_subchannel[4] /* 4 bytes */;
    char keytype_keyframe[4] /* 4 bytes */;
    char keytype_extreme[4] /* 4 bytes */;
    char keytype_breakdown[4] /* 4 bytes */;
    char keytype_jitter[4] /* 4 bytes */;
    char keytype_keyframe_select[4] /* 4 bytes */;
    char keytype_extreme_select[4] /* 4 bytes */;
    char keytype_breakdown_select[4] /* 4 bytes */;
    char keytype_jitter_select[4] /* 4 bytes */;
    char keyborder[4] /* 4 bytes */;
    char keyborder_select[4] /* 4 bytes */;
    char console_output[4] /* 4 bytes */;
    char console_input[4] /* 4 bytes */;
    char console_info[4] /* 4 bytes */;
    char console_error[4] /* 4 bytes */;
    char console_cursor[4] /* 4 bytes */;
    char console_select[4] /* 4 bytes */;
    char vertex_size /* 1 bytes */;
    char outline_width /* 1 bytes */;
    char facedot_size /* 1 bytes */;
    char noodle_curving /* 1 bytes */;
    char syntaxl[4] /* 4 bytes */;
    char syntaxs[4] /* 4 bytes */;
    char syntaxb[4] /* 4 bytes */;
    char syntaxn[4] /* 4 bytes */;
    char syntaxv[4] /* 4 bytes */;
    char syntaxc[4] /* 4 bytes */;
    char syntaxd[4] /* 4 bytes */;
    char syntaxr[4] /* 4 bytes */;
    char nodeclass_output[4] /* 4 bytes */;
    char nodeclass_filter[4] /* 4 bytes */;
    char nodeclass_vector[4] /* 4 bytes */;
    char nodeclass_texture[4] /* 4 bytes */;
    char nodeclass_shader[4] /* 4 bytes */;
    char nodeclass_script[4] /* 4 bytes */;
    char nodeclass_pattern[4] /* 4 bytes */;
    char nodeclass_layout[4] /* 4 bytes */;
    char movie[4] /* 4 bytes */;
    char movieclip[4] /* 4 bytes */;
    char mask[4] /* 4 bytes */;
    char image[4] /* 4 bytes */;
    char scene[4] /* 4 bytes */;
    char audio[4] /* 4 bytes */;
    char effect[4] /* 4 bytes */;
    char transition[4] /* 4 bytes */;
    char meta[4] /* 4 bytes */;
    char editmesh_active[4] /* 4 bytes */;
    char handle_vertex[4] /* 4 bytes */;
    char handle_vertex_select[4] /* 4 bytes */;
    char handle_vertex_size /* 1 bytes */;
    char clipping_border_3d[4] /* 4 bytes */;
    char marker_outline[4] /* 4 bytes */;
    char marker[4] /* 4 bytes */;
    char act_marker[4] /* 4 bytes */;
    char sel_marker[4] /* 4 bytes */;
    char dis_marker[4] /* 4 bytes */;
    char lock_marker[4] /* 4 bytes */;
    char bundle_solid[4] /* 4 bytes */;
    char path_before[4] /* 4 bytes */;
    char path_after[4] /* 4 bytes */;
    char camera_path[4] /* 4 bytes */;
    char hpad[2] /* 2 bytes */;
    char gp_vertex_size /* 1 bytes */;
    char gp_vertex[4] /* 4 bytes */;
    char gp_vertex_select[4] /* 4 bytes */;
    char preview_back[4] /* 4 bytes */;
    char preview_stitch_face[4] /* 4 bytes */;
    char preview_stitch_edge[4] /* 4 bytes */;
    char preview_stitch_vert[4] /* 4 bytes */;
    char preview_stitch_stitchable[4] /* 4 bytes */;
    char preview_stitch_unstitchable[4] /* 4 bytes */;
    char preview_stitch_active[4] /* 4 bytes */;
    char uv_shadow[4] /* 4 bytes */;
    char uv_others[4] /* 4 bytes */;
    char match[4] /* 4 bytes */;
    char selected_highlight[4] /* 4 bytes */;
    char skin_root[4] /* 4 bytes */;
    char anim_active[4] /* 4 bytes */;
    char anim_non_active[4] /* 4 bytes */;
    char nla_tweaking[4] /* 4 bytes */;
    char nla_tweakdupli[4] /* 4 bytes */;
    char nla_transition[4] /* 4 bytes */;
    char nla_transition_sel[4] /* 4 bytes */;
    char nla_meta[4] /* 4 bytes */;
    char nla_meta_sel[4] /* 4 bytes */;
    char nla_sound[4] /* 4 bytes */;
    char nla_sound_sel[4] /* 4 bytes */;
    char info_selected[4] /* 4 bytes */;
    char info_selected_text[4] /* 4 bytes */;
    char info_error[4] /* 4 bytes */;
    char info_error_text[4] /* 4 bytes */;
    char info_warning[4] /* 4 bytes */;
    char info_warning_text[4] /* 4 bytes */;
    char info_info[4] /* 4 bytes */;
    char info_info_text[4] /* 4 bytes */;
    char info_debug[4] /* 4 bytes */;
    char info_debug_text[4] /* 4 bytes */;
    char paint_curve_pivot[4] /* 4 bytes */;
    char paint_curve_handle[4] /* 4 bytes */;
};

struct ThemeWireColor {
    char solid[4] /* 4 bytes */;
    char select[4] /* 4 bytes */;
    char active[4] /* 4 bytes */;
    short flag /* 2 bytes */;
    short pad /* 2 bytes */;
};

struct bTheme {
    bTheme *next /* 8 bytes */;
    bTheme *prev /* 8 bytes */;
    char name[32] /* 32 bytes */;
    ThemeUI tui /* 912 bytes */;
    ThemeSpace tbuts /* 736 bytes */;
    ThemeSpace tv3d /* 736 bytes */;
    ThemeSpace tfile /* 736 bytes */;
    ThemeSpace tipo /* 736 bytes */;
    ThemeSpace tinfo /* 736 bytes */;
    ThemeSpace tact /* 736 bytes */;
    ThemeSpace tnla /* 736 bytes */;
    ThemeSpace tseq /* 736 bytes */;
    ThemeSpace tima /* 736 bytes */;
    ThemeSpace text /* 736 bytes */;
    ThemeSpace toops /* 736 bytes */;
    ThemeSpace ttime /* 736 bytes */;
    ThemeSpace tnode /* 736 bytes */;
    ThemeSpace tlogic /* 736 bytes */;
    ThemeSpace tuserpref /* 736 bytes */;
    ThemeSpace tconsole /* 736 bytes */;
    ThemeSpace tclip /* 736 bytes */;
    ThemeWireColor tarm[20] /* 320 bytes */;
    int active_theme_area /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct bAddon {
    bAddon *next /* 8 bytes */;
    bAddon *prev /* 8 bytes */;
    char module[64] /* 64 bytes */;
    IDProperty *prop /* 8 bytes */;
};

struct bPathCompare {
    bPathCompare *next /* 8 bytes */;
    bPathCompare *prev /* 8 bytes */;
    char path[768] /* 768 bytes */;
    char flag /* 1 bytes */;
    char pad[7] /* 7 bytes */;
};

struct SolidLight {
    int flag /* 4 bytes */;
    int pad /* 4 bytes */;
    float col[4] /* 16 bytes */;
    float spec[4] /* 16 bytes */;
    float vec[4] /* 16 bytes */;
};

struct WalkNavigation {
    float mouse_speed /* 4 bytes */;
    float walk_speed /* 4 bytes */;
    float walk_speed_factor /* 4 bytes */;
    float view_height /* 4 bytes */;
    float jump_height /* 4 bytes */;
    float teleport_time /* 4 bytes */;
    short flag /* 2 bytes */;
    short pad[3] /* 6 bytes */;
};

struct UserDef {
    int versionfile /* 4 bytes */;
    int subversionfile /* 4 bytes */;
    int flag /* 4 bytes */;
    int dupflag /* 4 bytes */;
    int savetime /* 4 bytes */;
    char tempdir[768] /* 768 bytes */;
    char fontdir[768] /* 768 bytes */;
    char renderdir[1024] /* 1024 bytes */;
    char render_cachedir[768] /* 768 bytes */;
    char textudir[768] /* 768 bytes */;
    char pythondir[768] /* 768 bytes */;
    char sounddir[768] /* 768 bytes */;
    char i18ndir[768] /* 768 bytes */;
    char image_editor[1024] /* 1024 bytes */;
    char anim_player[1024] /* 1024 bytes */;
    int anim_player_preset /* 4 bytes */;
    short v2d_min_gridsize /* 2 bytes */;
    short timecode_style /* 2 bytes */;
    short versions /* 2 bytes */;
    short dbl_click_time /* 2 bytes */;
    short gameflags /* 2 bytes */;
    short wheellinescroll /* 2 bytes */;
    int uiflag /* 4 bytes */;
    int uiflag2 /* 4 bytes */;
    int language /* 4 bytes */;
    short userpref /* 2 bytes */;
    short viewzoom /* 2 bytes */;
    int mixbufsize /* 4 bytes */;
    int audiodevice /* 4 bytes */;
    int audiorate /* 4 bytes */;
    int audioformat /* 4 bytes */;
    int audiochannels /* 4 bytes */;
    int scrollback /* 4 bytes */;
    int dpi /* 4 bytes */;
    char pad2[2] /* 2 bytes */;
    short transopts /* 2 bytes */;
    short menuthreshold1 /* 2 bytes */;
    short menuthreshold2 /* 2 bytes */;
    ListBase themes /* 16 bytes */;
    ListBase uifonts /* 16 bytes */;
    ListBase uistyles /* 16 bytes */;
    ListBase keymaps /* 16 bytes */;
    ListBase user_keymaps /* 16 bytes */;
    ListBase addons /* 16 bytes */;
    ListBase autoexec_paths /* 16 bytes */;
    char keyconfigstr[64] /* 64 bytes */;
    short undosteps /* 2 bytes */;
    short undomemory /* 2 bytes */;
    short gp_manhattendist /* 2 bytes */;
    short gp_euclideandist /* 2 bytes */;
    short gp_eraser /* 2 bytes */;
    short gp_settings /* 2 bytes */;
    short tb_leftmouse /* 2 bytes */;
    short tb_rightmouse /* 2 bytes */;
    SolidLight light[3] /* 168 bytes */;
    short tw_hotspot /* 2 bytes */;
    short tw_flag /* 2 bytes */;
    short tw_handlesize /* 2 bytes */;
    short tw_size /* 2 bytes */;
    short textimeout /* 2 bytes */;
    short texcollectrate /* 2 bytes */;
    short wmdrawmethod /* 2 bytes */;
    short dragthreshold /* 2 bytes */;
    int memcachelimit /* 4 bytes */;
    int prefetchframes /* 4 bytes */;
    short frameserverport /* 2 bytes */;
    short pad_rot_angle /* 2 bytes */;
    short obcenter_dia /* 2 bytes */;
    short rvisize /* 2 bytes */;
    short rvibright /* 2 bytes */;
    short recent_files /* 2 bytes */;
    short smooth_viewtx /* 2 bytes */;
    short glreslimit /* 2 bytes */;
    short curssize /* 2 bytes */;
    short color_picker_type /* 2 bytes */;
    char ipo_new /* 1 bytes */;
    char keyhandles_new /* 1 bytes */;
    char gpu_select_method /* 1 bytes */;
    char pad1 /* 1 bytes */;
    short scrcastfps /* 2 bytes */;
    short scrcastwait /* 2 bytes */;
    short widget_unit /* 2 bytes */;
    short anisotropic_filter /* 2 bytes */;
    short use_16bit_textures /* 2 bytes */;
    short use_gpu_mipmap /* 2 bytes */;
    float ndof_sensitivity /* 4 bytes */;
    float ndof_orbit_sensitivity /* 4 bytes */;
    int ndof_flag /* 4 bytes */;
    short ogl_multisamples /* 2 bytes */;
    short image_draw_method /* 2 bytes */;
    float glalphaclip /* 4 bytes */;
    short autokey_mode /* 2 bytes */;
    short autokey_flag /* 2 bytes */;
    short text_render /* 2 bytes */;
    short pad9 /* 2 bytes */;
    ColorBand coba_weight /* 776 bytes */;
    float sculpt_paint_overlay_col[3] /* 12 bytes */;
    float gpencil_new_layer_col[4] /* 16 bytes */;
    short tweak_threshold /* 2 bytes */;
    char navigation_mode /* 1 bytes */;
    char pad /* 1 bytes */;
    char author[80] /* 80 bytes */;
    char font_path_ui[1024] /* 1024 bytes */;
    int compute_device_type /* 4 bytes */;
    int compute_device_id /* 4 bytes */;
    float fcu_inactive_alpha /* 4 bytes */;
    float pixelsize /* 4 bytes */;
    int virtual_pixel /* 4 bytes */;
    short pie_interaction_type /* 2 bytes */;
    short pie_initial_timeout /* 2 bytes */;
    short pie_animation_timeout /* 2 bytes */;
    short pie_menu_confirm /* 2 bytes */;
    short pie_menu_radius /* 2 bytes */;
    short pie_menu_threshold /* 2 bytes */;
    WalkNavigation walk_navigation /* 32 bytes */;
};

struct bScreen {
    ID id /* 120 bytes */;
    ListBase vertbase /* 16 bytes */;
    ListBase edgebase /* 16 bytes */;
    ListBase areabase /* 16 bytes */;
    ListBase regionbase /* 16 bytes */;
    Scene *scene /* 8 bytes */;
    Scene *newscene /* 8 bytes */;
    short winid /* 2 bytes */;
    short redraws_flag /* 2 bytes */;
    char temp /* 1 bytes */;
    char state /* 1 bytes */;
    char do_draw /* 1 bytes */;
    char do_refresh /* 1 bytes */;
    char do_draw_gesture /* 1 bytes */;
    char do_draw_paintcursor /* 1 bytes */;
    char do_draw_drag /* 1 bytes */;
    char swap /* 1 bytes */;
    char skip_handling /* 1 bytes */;
    char pad[7] /* 7 bytes */;
    short mainwin /* 2 bytes */;
    short subwinactive /* 2 bytes */;
    void *animtimer /* 8 bytes */;
    void *context /* 8 bytes */;
};

struct ScrVert {
    ScrVert *next /* 8 bytes */;
    ScrVert *prev /* 8 bytes */;
    ScrVert *newv /* 8 bytes */;
    vec2s vec /* 4 bytes */;
    short flag /* 2 bytes */;
    short editflag /* 2 bytes */;
};

struct ScrEdge {
    ScrEdge *next /* 8 bytes */;
    ScrEdge *prev /* 8 bytes */;
    ScrVert *v1 /* 8 bytes */;
    ScrVert *v2 /* 8 bytes */;
    short border /* 2 bytes */;
    short flag /* 2 bytes */;
    int pad /* 4 bytes */;
};

struct Panel {
    Panel *next /* 8 bytes */;
    Panel *prev /* 8 bytes */;
    void *type /* 8 bytes */;
    void *layout /* 8 bytes */;
    char panelname[64] /* 64 bytes */;
    char tabname[64] /* 64 bytes */;
    char drawname[64] /* 64 bytes */;
    int ofsx /* 4 bytes */;
    int ofsy /* 4 bytes */;
    int sizex /* 4 bytes */;
    int sizey /* 4 bytes */;
    short labelofs /* 2 bytes */;
    short pad /* 2 bytes */;
    short flag /* 2 bytes */;
    short runtime_flag /* 2 bytes */;
    short control /* 2 bytes */;
    short snap /* 2 bytes */;
    int sortorder /* 4 bytes */;
    Panel *paneltab /* 8 bytes */;
    void *activedata /* 8 bytes */;
};

struct PanelCategoryStack {
    PanelCategoryStack *next /* 8 bytes */;
    PanelCategoryStack *prev /* 8 bytes */;
    char idname[64] /* 64 bytes */;
};

struct uiList {
    uiList *next /* 8 bytes */;
    uiList *prev /* 8 bytes */;
    void *type /* 8 bytes */;
    char list_id[64] /* 64 bytes */;
    int layout_type /* 4 bytes */;
    int flag /* 4 bytes */;
    int list_scroll /* 4 bytes */;
    int list_grip /* 4 bytes */;
    int list_last_len /* 4 bytes */;
    int list_last_activei /* 4 bytes */;
    char filter_byname[64] /* 64 bytes */;
    int filter_flag /* 4 bytes */;
    int filter_sort_flag /* 4 bytes */;
    IDProperty *properties /* 8 bytes */;
    void *dyn_data /* 8 bytes */;
};

struct uiPreview {
    uiPreview *next /* 8 bytes */;
    uiPreview *prev /* 8 bytes */;
    char preview_id[64] /* 64 bytes */;
    short height /* 2 bytes */;
    short pad1[3] /* 6 bytes */;
};

struct ScrArea {
    ScrArea *next /* 8 bytes */;
    ScrArea *prev /* 8 bytes */;
    ScrVert *v1 /* 8 bytes */;
    ScrVert *v2 /* 8 bytes */;
    ScrVert *v3 /* 8 bytes */;
    ScrVert *v4 /* 8 bytes */;
    bScreen *full /* 8 bytes */;
    rcti totrct /* 16 bytes */;
    char spacetype /* 1 bytes */;
    char butspacetype /* 1 bytes */;
    short winx /* 2 bytes */;
    short winy /* 2 bytes */;
    short headertype /* 2 bytes */;
    short do_refresh /* 2 bytes */;
    short flag /* 2 bytes */;
    short region_active_win /* 2 bytes */;
    char temp /* 1 bytes */;
    char pad /* 1 bytes */;
    void *type /* 8 bytes */;
    ListBase spacedata /* 16 bytes */;
    ListBase regionbase /* 16 bytes */;
    ListBase handlers /* 16 bytes */;
    ListBase actionzones /* 16 bytes */;
};

struct ARegion {
    ARegion *next /* 8 bytes */;
    ARegion *prev /* 8 bytes */;
    View2D v2d /* 160 bytes */;
    rcti winrct /* 16 bytes */;
    rcti drawrct /* 16 bytes */;
    short winx /* 2 bytes */;
    short winy /* 2 bytes */;
    short swinid /* 2 bytes */;
    short regiontype /* 2 bytes */;
    short alignment /* 2 bytes */;
    short flag /* 2 bytes */;
    float fsize /* 4 bytes */;
    short sizex /* 2 bytes */;
    short sizey /* 2 bytes */;
    short do_draw /* 2 bytes */;
    short do_draw_overlay /* 2 bytes */;
    short swap /* 2 bytes */;
    short overlap /* 2 bytes */;
    short flagfullscreen /* 2 bytes */;
    short pad /* 2 bytes */;
    void *type /* 8 bytes */;
    ListBase uiblocks /* 16 bytes */;
    ListBase panels /* 16 bytes */;
    ListBase panels_category_active /* 16 bytes */;
    ListBase ui_lists /* 16 bytes */;
    ListBase ui_previews /* 16 bytes */;
    ListBase handlers /* 16 bytes */;
    ListBase panels_category /* 16 bytes */;
    void *regiontimer /* 8 bytes */;
    char *headerstr /* 8 bytes */;
    void *regiondata /* 8 bytes */;
};

struct FileGlobal {
    char subvstr[4] /* 4 bytes */;
    short subversion /* 2 bytes */;
    short minversion /* 2 bytes */;
    short minsubversion /* 2 bytes */;
    char pad[6] /* 6 bytes */;
    bScreen *curscreen /* 8 bytes */;
    Scene *curscene /* 8 bytes */;
    int fileflags /* 4 bytes */;
    int globalf /* 4 bytes */;
    uint64_t build_commit_timestamp /* 8 bytes */;
    char build_hash[16] /* 16 bytes */;
    char filename[1024] /* 1024 bytes */;
};

struct StripElem {
    char name[256] /* 256 bytes */;
    int orig_width /* 4 bytes */;
    int orig_height /* 4 bytes */;
};

struct StripCrop {
    int top /* 4 bytes */;
    int bottom /* 4 bytes */;
    int left /* 4 bytes */;
    int right /* 4 bytes */;
};

struct StripTransform {
    int xofs /* 4 bytes */;
    int yofs /* 4 bytes */;
};

struct StripColorBalance {
    float lift[3] /* 12 bytes */;
    float gamma[3] /* 12 bytes */;
    float gain[3] /* 12 bytes */;
    int flag /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct StripProxy {
    char dir[768] /* 768 bytes */;
    char file[256] /* 256 bytes */;
    void *anim /* 8 bytes */;
    short tc /* 2 bytes */;
    short quality /* 2 bytes */;
    short build_size_flags /* 2 bytes */;
    short build_tc_flags /* 2 bytes */;
    short build_flags /* 2 bytes */;
    char pad[6] /* 6 bytes */;
};

struct Strip {
    Strip *next /* 8 bytes */;
    Strip *prev /* 8 bytes */;
    int us /* 4 bytes */;
    int done /* 4 bytes */;
    int startstill /* 4 bytes */;
    int endstill /* 4 bytes */;
    StripElem *stripdata /* 8 bytes */;
    char dir[768] /* 768 bytes */;
    StripProxy *proxy /* 8 bytes */;
    StripCrop *crop /* 8 bytes */;
    StripTransform *transform /* 8 bytes */;
    StripColorBalance *color_balance /* 8 bytes */;
    ColorManagedColorspaceSettings colorspace_settings /* 64 bytes */;
};

struct Sequence {
    Sequence *next /* 8 bytes */;
    Sequence *prev /* 8 bytes */;
    void *tmp /* 8 bytes */;
    void *lib /* 8 bytes */;
    char name[64] /* 64 bytes */;
    int flag /* 4 bytes */;
    int type /* 4 bytes */;
    int len /* 4 bytes */;
    int start /* 4 bytes */;
    int startofs /* 4 bytes */;
    int endofs /* 4 bytes */;
    int startstill /* 4 bytes */;
    int endstill /* 4 bytes */;
    int machine /* 4 bytes */;
    int depth /* 4 bytes */;
    int startdisp /* 4 bytes */;
    int enddisp /* 4 bytes */;
    float sat /* 4 bytes */;
    float mul /* 4 bytes */;
    float handsize /* 4 bytes */;
    short anim_preseek /* 2 bytes */;
    short streamindex /* 2 bytes */;
    int multicam_source /* 4 bytes */;
    int clip_flag /* 4 bytes */;
    Strip *strip /* 8 bytes */;
    Ipo *ipo /* 8 bytes */;
    Scene *scene /* 8 bytes */;
    Object *scene_camera /* 8 bytes */;
    MovieClip *clip /* 8 bytes */;
    Mask *mask /* 8 bytes */;
    void *anim /* 8 bytes */;
    float effect_fader /* 4 bytes */;
    float speed_fader /* 4 bytes */;
    Sequence *seq1 /* 8 bytes */;
    Sequence *seq2 /* 8 bytes */;
    Sequence *seq3 /* 8 bytes */;
    ListBase seqbase /* 16 bytes */;
    bSound *sound /* 8 bytes */;
    void *scene_sound /* 8 bytes */;
    float volume /* 4 bytes */;
    float pitch /* 4 bytes */;
    float pan /* 4 bytes */;
    float strobe /* 4 bytes */;
    void *effectdata /* 8 bytes */;
    int anim_startofs /* 4 bytes */;
    int anim_endofs /* 4 bytes */;
    int blend_mode /* 4 bytes */;
    float blend_opacity /* 4 bytes */;
    int sfra /* 4 bytes */;
    char alpha_mode /* 1 bytes */;
    char pad[3] /* 3 bytes */;
    ListBase modifiers /* 16 bytes */;
};

struct MetaStack {
    MetaStack *next /* 8 bytes */;
    MetaStack *prev /* 8 bytes */;
    ListBase *oldbasep /* 8 bytes */;
    Sequence *parseq /* 8 bytes */;
    int disp_range[2] /* 8 bytes */;
};

struct Editing {
    ListBase *seqbasep /* 8 bytes */;
    ListBase seqbase /* 16 bytes */;
    ListBase metastack /* 16 bytes */;
    Sequence *act_seq /* 8 bytes */;
    char act_imagedir[1024] /* 1024 bytes */;
    char act_sounddir[1024] /* 1024 bytes */;
    int over_ofs /* 4 bytes */;
    int over_cfra /* 4 bytes */;
    int over_flag /* 4 bytes */;
    int pad /* 4 bytes */;
    rctf over_border /* 16 bytes */;
};

struct WipeVars {
    float edgeWidth /* 4 bytes */;
    float angle /* 4 bytes */;
    short forward /* 2 bytes */;
    short wipetype /* 2 bytes */;
};

struct GlowVars {
    float fMini /* 4 bytes */;
    float fClamp /* 4 bytes */;
    float fBoost /* 4 bytes */;
    float dDist /* 4 bytes */;
    int dQuality /* 4 bytes */;
    int bNoComp /* 4 bytes */;
};

struct TransformVars {
    float ScalexIni /* 4 bytes */;
    float ScaleyIni /* 4 bytes */;
    float xIni /* 4 bytes */;
    float yIni /* 4 bytes */;
    float rotIni /* 4 bytes */;
    int percent /* 4 bytes */;
    int interpolation /* 4 bytes */;
    int uniform_scale /* 4 bytes */;
};

struct SolidColorVars {
    float col[3] /* 12 bytes */;
    float pad /* 4 bytes */;
};

struct SpeedControlVars {
    float *frameMap /* 8 bytes */;
    float globalSpeed /* 4 bytes */;
    int flags /* 4 bytes */;
    int length /* 4 bytes */;
    int lastValidFrame /* 4 bytes */;
};

struct GaussianBlurVars {
    float size_x /* 4 bytes */;
    float size_y /* 4 bytes */;
};

struct SequenceModifierData {
    SequenceModifierData *next /* 8 bytes */;
    SequenceModifierData *prev /* 8 bytes */;
    int type /* 4 bytes */;
    int flag /* 4 bytes */;
    char name[64] /* 64 bytes */;
    int mask_input_type /* 4 bytes */;
    int pad /* 4 bytes */;
    Sequence *mask_sequence /* 8 bytes */;
    Mask *mask_id /* 8 bytes */;
};

struct ColorBalanceModifierData {
    SequenceModifierData modifier /* 112 bytes */;
    StripColorBalance color_balance /* 44 bytes */;
    float color_multiply /* 4 bytes */;
};

struct CurveMap {
    short totpoint /* 2 bytes */;
    short flag /* 2 bytes */;
    float range /* 4 bytes */;
    float mintable /* 4 bytes */;
    float maxtable /* 4 bytes */;
    float ext_in[2] /* 8 bytes */;
    float ext_out[2] /* 8 bytes */;
    CurveMapPoint *curve /* 8 bytes */;
    CurveMapPoint *table /* 8 bytes */;
    CurveMapPoint *premultable /* 8 bytes */;
    float premul_ext_in[2] /* 8 bytes */;
    float premul_ext_out[2] /* 8 bytes */;
};

struct CurveMapping {
    int flag /* 4 bytes */;
    int cur /* 4 bytes */;
    int preset /* 4 bytes */;
    int changed_timestamp /* 4 bytes */;
    rctf curr /* 16 bytes */;
    rctf clipr /* 16 bytes */;
    CurveMap cm[4] /* 288 bytes */;
    float black[3] /* 12 bytes */;
    float white[3] /* 12 bytes */;
    float bwmul[3] /* 12 bytes */;
    float sample[3] /* 12 bytes */;
};

struct CurvesModifierData {
    SequenceModifierData modifier /* 112 bytes */;
    CurveMapping curve_mapping /* 384 bytes */;
};

struct HueCorrectModifierData {
    SequenceModifierData modifier /* 112 bytes */;
    CurveMapping curve_mapping /* 384 bytes */;
};

struct BrightContrastModifierData {
    SequenceModifierData modifier /* 112 bytes */;
    float bright /* 4 bytes */;
    float contrast /* 4 bytes */;
};

struct SequencerMaskModifierData {
    SequenceModifierData modifier /* 112 bytes */;
};

struct Effect {
    Effect *next /* 8 bytes */;
    Effect *prev /* 8 bytes */;
    short type /* 2 bytes */;
    short flag /* 2 bytes */;
    short buttype /* 2 bytes */;
    short rt /* 2 bytes */;
};

struct BuildEff {
    BuildEff *next /* 8 bytes */;
    BuildEff *prev /* 8 bytes */;
    short type /* 2 bytes */;
    short flag /* 2 bytes */;
    short buttype /* 2 bytes */;
    short rt /* 2 bytes */;
    float len /* 4 bytes */;
    float sfra /* 4 bytes */;
};

struct PartEff {
    PartEff *next /* 8 bytes */;
    PartEff *prev /* 8 bytes */;
    short type /* 2 bytes */;
    short flag /* 2 bytes */;
    short buttype /* 2 bytes */;
    short stype /* 2 bytes */;
    short vertgroup /* 2 bytes */;
    short userjit /* 2 bytes */;
    float sta /* 4 bytes */;
    float end /* 4 bytes */;
    float lifetime /* 4 bytes */;
    int totpart /* 4 bytes */;
    int totkey /* 4 bytes */;
    int seed /* 4 bytes */;
    float normfac /* 4 bytes */;
    float obfac /* 4 bytes */;
    float randfac /* 4 bytes */;
    float texfac /* 4 bytes */;
    float randlife /* 4 bytes */;
    float force[3] /* 12 bytes */;
    float damp /* 4 bytes */;
    float nabla /* 4 bytes */;
    float vectsize /* 4 bytes */;
    float maxlen /* 4 bytes */;
    float pad /* 4 bytes */;
    float defvec[3] /* 12 bytes */;
    float mult[4] /* 16 bytes */;
    float life[4] /* 16 bytes */;
    short child[4] /* 8 bytes */;
    short mat[4] /* 8 bytes */;
    short texmap /* 2 bytes */;
    short curmult /* 2 bytes */;
    short staticstep /* 2 bytes */;
    short omat /* 2 bytes */;
    short timetex /* 2 bytes */;
    short speedtex /* 2 bytes */;
    short flag2 /* 2 bytes */;
    short flag2neg /* 2 bytes */;
    short disp /* 2 bytes */;
    short vertgroup_v /* 2 bytes */;
    char vgroupname[64] /* 64 bytes */;
    char vgroupname_v[64] /* 64 bytes */;
    float imat[4][4] /* 64 bytes */;
    void *keys /* 8 bytes */;
    Group *group /* 8 bytes */;
};

struct WaveEff {
    WaveEff *next /* 8 bytes */;
    WaveEff *prev /* 8 bytes */;
    short type /* 2 bytes */;
    short flag /* 2 bytes */;
    short buttype /* 2 bytes */;
    short stype /* 2 bytes */;
    float startx /* 4 bytes */;
    float starty /* 4 bytes */;
    float height /* 4 bytes */;
    float width /* 4 bytes */;
    float narrow /* 4 bytes */;
    float speed /* 4 bytes */;
    float minfac /* 4 bytes */;
    float damp /* 4 bytes */;
    float timeoffs /* 4 bytes */;
    float lifetime /* 4 bytes */;
};

struct TreeStore {
    int totelem /* 4 bytes */;
    int usedelem /* 4 bytes */;
    TreeStoreElem *data /* 8 bytes */;
};

struct bProperty {
    bProperty *next /* 8 bytes */;
    bProperty *prev /* 8 bytes */;
    char name[64] /* 64 bytes */;
    short type /* 2 bytes */;
    short flag /* 2 bytes */;
    int data /* 4 bytes */;
    void *poin /* 8 bytes */;
};

struct bNearSensor {
    char name[64] /* 64 bytes */;
    float dist /* 4 bytes */;
    float resetdist /* 4 bytes */;
    int lastval /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct bMouseSensor {
    short type /* 2 bytes */;
    short flag /* 2 bytes */;
    short pad1 /* 2 bytes */;
    short mode /* 2 bytes */;
    char propname[64] /* 64 bytes */;
    char matname[64] /* 64 bytes */;
};

struct bTouchSensor {
    char name[64] /* 64 bytes */;
    Material *ma /* 8 bytes */;
    float dist /* 4 bytes */;
    float pad /* 4 bytes */;
};

struct bKeyboardSensor {
    short key /* 2 bytes */;
    short qual /* 2 bytes */;
    short type /* 2 bytes */;
    short qual2 /* 2 bytes */;
    char targetName[64] /* 64 bytes */;
    char toggleName[64] /* 64 bytes */;
};

struct bPropertySensor {
    int type /* 4 bytes */;
    int pad /* 4 bytes */;
    char name[64] /* 64 bytes */;
    char value[64] /* 64 bytes */;
    char maxvalue[64] /* 64 bytes */;
};

struct bActuatorSensor {
    int type /* 4 bytes */;
    int pad /* 4 bytes */;
    char name[64] /* 64 bytes */;
};

struct bDelaySensor {
    short delay /* 2 bytes */;
    short duration /* 2 bytes */;
    short flag /* 2 bytes */;
    short pad /* 2 bytes */;
};

struct bCollisionSensor {
    char name[64] /* 64 bytes */;
    char materialName[64] /* 64 bytes */;
    short damptimer /* 2 bytes */;
    short damp /* 2 bytes */;
    short mode /* 2 bytes */;
    short pad2 /* 2 bytes */;
};

struct bRadarSensor {
    char name[64] /* 64 bytes */;
    float angle /* 4 bytes */;
    float range /* 4 bytes */;
    short flag /* 2 bytes */;
    short axis /* 2 bytes */;
};

struct bRandomSensor {
    char name[64] /* 64 bytes */;
    int seed /* 4 bytes */;
    int delay /* 4 bytes */;
};

struct bRaySensor {
    char name[64] /* 64 bytes */;
    float range /* 4 bytes */;
    char propname[64] /* 64 bytes */;
    char matname[64] /* 64 bytes */;
    short mode /* 2 bytes */;
    short pad1 /* 2 bytes */;
    int axisflag /* 4 bytes */;
};

struct bArmatureSensor {
    char posechannel[64] /* 64 bytes */;
    char constraint[64] /* 64 bytes */;
    int type /* 4 bytes */;
    float value /* 4 bytes */;
};

struct bMessageSensor {
    Object *fromObject /* 8 bytes */;
    char subject[64] /* 64 bytes */;
    char body[64] /* 64 bytes */;
};

struct bSensor {
    bSensor *next /* 8 bytes */;
    bSensor *prev /* 8 bytes */;
    short type /* 2 bytes */;
    short otype /* 2 bytes */;
    short flag /* 2 bytes */;
    short pulse /* 2 bytes */;
    short freq /* 2 bytes */;
    short totlinks /* 2 bytes */;
    short pad1 /* 2 bytes */;
    short pad2 /* 2 bytes */;
    char name[64] /* 64 bytes */;
    void *data /* 8 bytes */;
    bController **links /* 8 bytes */;
    Object *ob /* 8 bytes */;
    short invert /* 2 bytes */;
    short level /* 2 bytes */;
    short tap /* 2 bytes */;
    short pad /* 2 bytes */;
};

struct bJoystickSensor {
    char name[64] /* 64 bytes */;
    char type /* 1 bytes */;
    char joyindex /* 1 bytes */;
    short flag /* 2 bytes */;
    short axis /* 2 bytes */;
    short axis_single /* 2 bytes */;
    int axisf /* 4 bytes */;
    int button /* 4 bytes */;
    int hat /* 4 bytes */;
    int hatf /* 4 bytes */;
    int precision /* 4 bytes */;
};

struct bExpressionCont {
    char str[128] /* 128 bytes */;
};

struct bPythonCont {
    Text *text /* 8 bytes */;
    char module[64] /* 64 bytes */;
    int mode /* 4 bytes */;
    int flag /* 4 bytes */;
};

struct bController {
    bController *next /* 8 bytes */;
    bController *prev /* 8 bytes */;
    bController *mynew /* 8 bytes */;
    short type /* 2 bytes */;
    short flag /* 2 bytes */;
    short inputs /* 2 bytes */;
    short totlinks /* 2 bytes */;
    short otype /* 2 bytes */;
    short totslinks /* 2 bytes */;
    short pad2 /* 2 bytes */;
    short pad3 /* 2 bytes */;
    char name[64] /* 64 bytes */;
    void *data /* 8 bytes */;
    bActuator **links /* 8 bytes */;
    bSensor **slinks /* 8 bytes */;
    short val /* 2 bytes */;
    short valo /* 2 bytes */;
    int state_mask /* 4 bytes */;
};

struct bAddObjectActuator {
    int time /* 4 bytes */;
    int pad /* 4 bytes */;
    Object *ob /* 8 bytes */;
};

struct bActionActuator {
    bAction *act /* 8 bytes */;
    short type /* 2 bytes */;
    short flag /* 2 bytes */;
    float sta /* 4 bytes */;
    float end /* 4 bytes */;
    char name[64] /* 64 bytes */;
    char frameProp[64] /* 64 bytes */;
    short blendin /* 2 bytes */;
    short priority /* 2 bytes */;
    short layer /* 2 bytes */;
    short end_reset /* 2 bytes */;
    short strideaxis /* 2 bytes */;
    short blend_mode /* 2 bytes */;
    float stridelength /* 4 bytes */;
    float layer_weight /* 4 bytes */;
};

struct Sound3D {
    float min_gain /* 4 bytes */;
    float max_gain /* 4 bytes */;
    float reference_distance /* 4 bytes */;
    float max_distance /* 4 bytes */;
    float rolloff_factor /* 4 bytes */;
    float cone_inner_angle /* 4 bytes */;
    float cone_outer_angle /* 4 bytes */;
    float cone_outer_gain /* 4 bytes */;
};

struct bSoundActuator {
    short flag /* 2 bytes */;
    short sndnr /* 2 bytes */;
    int pad1 /* 4 bytes */;
    int pad2 /* 4 bytes */;
    short pad3[2] /* 4 bytes */;
    float volume /* 4 bytes */;
    float pitch /* 4 bytes */;
    bSound *sound /* 8 bytes */;
    Sound3D sound3D /* 32 bytes */;
    short type /* 2 bytes */;
    short pad4 /* 2 bytes */;
    short pad5 /* 2 bytes */;
    short pad6[1] /* 2 bytes */;
};

struct bEditObjectActuator {
    int time /* 4 bytes */;
    short type /* 2 bytes */;
    short flag /* 2 bytes */;
    Object *ob /* 8 bytes */;
    Mesh *me /* 8 bytes */;
    char name[64] /* 64 bytes */;
    float linVelocity[3] /* 12 bytes */;
    float angVelocity[3] /* 12 bytes */;
    float mass /* 4 bytes */;
    short localflag /* 2 bytes */;
    short dyn_operation /* 2 bytes */;
    short upflag /* 2 bytes */;
    short trackflag /* 2 bytes */;
    int pad /* 4 bytes */;
};

struct bSceneActuator {
    short type /* 2 bytes */;
    short pad1 /* 2 bytes */;
    int pad /* 4 bytes */;
    Scene *scene /* 8 bytes */;
    Object *camera /* 8 bytes */;
};

struct bPropertyActuator {
    int pad /* 4 bytes */;
    int type /* 4 bytes */;
    char name[64] /* 64 bytes */;
    char value[64] /* 64 bytes */;
    Object *ob /* 8 bytes */;
};

struct bObjectActuator {
    short flag /* 2 bytes */;
    short type /* 2 bytes */;
    short otype /* 2 bytes */;
    short damping /* 2 bytes */;
    float forceloc[3] /* 12 bytes */;
    float forcerot[3] /* 12 bytes */;
    float pad[3] /* 12 bytes */;
    float pad1[3] /* 12 bytes */;
    float dloc[3] /* 12 bytes */;
    float drot[3] /* 12 bytes */;
    float linearvelocity[3] /* 12 bytes */;
    float angularvelocity[3] /* 12 bytes */;
    Object *reference /* 8 bytes */;
};

struct bIpoActuator {
    short flag /* 2 bytes */;
    short type /* 2 bytes */;
    float sta /* 4 bytes */;
    float end /* 4 bytes */;
    char name[64] /* 64 bytes */;
    char frameProp[64] /* 64 bytes */;
    short pad1 /* 2 bytes */;
    short pad2 /* 2 bytes */;
    short pad3 /* 2 bytes */;
    short pad4 /* 2 bytes */;
};

struct bCameraActuator {
    Object *ob /* 8 bytes */;
    float height /* 4 bytes */;
    float min /* 4 bytes */;
    float max /* 4 bytes */;
    float damping /* 4 bytes */;
    short pad1 /* 2 bytes */;
    short axis /* 2 bytes */;
    float pad2 /* 4 bytes */;
};

struct bConstraintActuator {
    short type /* 2 bytes */;
    short mode /* 2 bytes */;
    short flag /* 2 bytes */;
    short damp /* 2 bytes */;
    short time /* 2 bytes */;
    short rotdamp /* 2 bytes */;
    int pad /* 4 bytes */;
    float minloc[3] /* 12 bytes */;
    float maxloc[3] /* 12 bytes */;
    float minrot[3] /* 12 bytes */;
    float maxrot[3] /* 12 bytes */;
    char matprop[64] /* 64 bytes */;
};

struct bGroupActuator {
    short flag /* 2 bytes */;
    short type /* 2 bytes */;
    int sta /* 4 bytes */;
    int end /* 4 bytes */;
    char name[64] /* 64 bytes */;
    short pad[3] /* 6 bytes */;
    short cur /* 2 bytes */;
    short butsta /* 2 bytes */;
    short butend /* 2 bytes */;
};

struct bRandomActuator {
    int seed /* 4 bytes */;
    int distribution /* 4 bytes */;
    int int_arg_1 /* 4 bytes */;
    int int_arg_2 /* 4 bytes */;
    float float_arg_1 /* 4 bytes */;
    float float_arg_2 /* 4 bytes */;
    char propname[64] /* 64 bytes */;
};

struct bMessageActuator {
    char toPropName[64] /* 64 bytes */;
    Object *toObject /* 8 bytes */;
    char subject[64] /* 64 bytes */;
    short bodyType /* 2 bytes */;
    short pad1 /* 2 bytes */;
    int pad2 /* 4 bytes */;
    char body[64] /* 64 bytes */;
};

struct bGameActuator {
    short flag /* 2 bytes */;
    short type /* 2 bytes */;
    int sta /* 4 bytes */;
    int end /* 4 bytes */;
    char filename[64] /* 64 bytes */;
    char loadaniname[64] /* 64 bytes */;
};

struct bVisibilityActuator {
    int flag /* 4 bytes */;
};

struct bTwoDFilterActuator {
    char pad[4] /* 4 bytes */;
    short type /* 2 bytes */;
    short flag /* 2 bytes */;
    int int_arg /* 4 bytes */;
    float float_arg /* 4 bytes */;
    Text *text /* 8 bytes */;
};

struct bParentActuator {
    char pad[2] /* 2 bytes */;
    short flag /* 2 bytes */;
    int type /* 4 bytes */;
    Object *ob /* 8 bytes */;
};

struct bStateActuator {
    int type /* 4 bytes */;
    int mask /* 4 bytes */;
};

struct bArmatureActuator {
    char posechannel[64] /* 64 bytes */;
    char constraint[64] /* 64 bytes */;
    int type /* 4 bytes */;
    float weight /* 4 bytes */;
    float influence /* 4 bytes */;
    float pad /* 4 bytes */;
    Object *target /* 8 bytes */;
    Object *subtarget /* 8 bytes */;
};

struct bSteeringActuator {
    char pad[5] /* 5 bytes */;
    char flag /* 1 bytes */;
    short facingaxis /* 2 bytes */;
    int type /* 4 bytes */;
    float dist /* 4 bytes */;
    float velocity /* 4 bytes */;
    float acceleration /* 4 bytes */;
    float turnspeed /* 4 bytes */;
    int updateTime /* 4 bytes */;
    Object *target /* 8 bytes */;
    Object *navmesh /* 8 bytes */;
};

struct bMouseActuator {
    short type /* 2 bytes */;
    short flag /* 2 bytes */;
    int object_axis[2] /* 8 bytes */;
    float threshold[2] /* 8 bytes */;
    float sensitivity[2] /* 8 bytes */;
    float limit_x[2] /* 8 bytes */;
    float limit_y[2] /* 8 bytes */;
};

struct bActuator {
    bActuator *next /* 8 bytes */;
    bActuator *prev /* 8 bytes */;
    bActuator *mynew /* 8 bytes */;
    short type /* 2 bytes */;
    short flag /* 2 bytes */;
    short otype /* 2 bytes */;
    short go /* 2 bytes */;
    char name[64] /* 64 bytes */;
    void *data /* 8 bytes */;
    Object *ob /* 8 bytes */;
};

struct bSound {
    ID id /* 120 bytes */;
    char name[1024] /* 1024 bytes */;
    PackedFile *packedfile /* 8 bytes */;
    void *handle /* 8 bytes */;
    PackedFile *newpackedfile /* 8 bytes */;
    Ipo *ipo /* 8 bytes */;
    float volume /* 4 bytes */;
    float attenuation /* 4 bytes */;
    float pitch /* 4 bytes */;
    float min_gain /* 4 bytes */;
    float max_gain /* 4 bytes */;
    float distance /* 4 bytes */;
    int flags /* 4 bytes */;
    int pad /* 4 bytes */;
    void *cache /* 8 bytes */;
    void *waveform /* 8 bytes */;
    void *playback_handle /* 8 bytes */;
    void *spinlock /* 8 bytes */;
};

struct GroupObject {
    GroupObject *next /* 8 bytes */;
    GroupObject *prev /* 8 bytes */;
    Object *ob /* 8 bytes */;
    void *lampren /* 8 bytes */;
    short recalc /* 2 bytes */;
    char pad[6] /* 6 bytes */;
};

struct Group {
    ID id /* 120 bytes */;
    ListBase gobject /* 16 bytes */;
    int layer /* 4 bytes */;
    float dupli_ofs[3] /* 12 bytes */;
};

struct Bone {
    Bone *next /* 8 bytes */;
    Bone *prev /* 8 bytes */;
    IDProperty *prop /* 8 bytes */;
    Bone *parent /* 8 bytes */;
    ListBase childbase /* 16 bytes */;
    char name[64] /* 64 bytes */;
    float roll /* 4 bytes */;
    float head[3] /* 12 bytes */;
    float tail[3] /* 12 bytes */;
    float bone_mat[3][3] /* 36 bytes */;
    int flag /* 4 bytes */;
    float arm_head[3] /* 12 bytes */;
    float arm_tail[3] /* 12 bytes */;
    float arm_mat[4][4] /* 64 bytes */;
    float arm_roll /* 4 bytes */;
    float dist /* 4 bytes */;
    float weight /* 4 bytes */;
    float xwidth /* 4 bytes */;
    float length /* 4 bytes */;
    float zwidth /* 4 bytes */;
    float ease1 /* 4 bytes */;
    float ease2 /* 4 bytes */;
    float rad_head /* 4 bytes */;
    float rad_tail /* 4 bytes */;
    float size[3] /* 12 bytes */;
    int layer /* 4 bytes */;
    short segments /* 2 bytes */;
    short pad[1] /* 2 bytes */;
};

struct bArmature {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
    ListBase bonebase /* 16 bytes */;
    ListBase chainbase /* 16 bytes */;
    ListBase *edbo /* 8 bytes */;
    Bone *act_bone /* 8 bytes */;
    void *act_edbone /* 8 bytes */;
    void *sketch /* 8 bytes */;
    int flag /* 4 bytes */;
    int drawtype /* 4 bytes */;
    int gevertdeformer /* 4 bytes */;
    int pad /* 4 bytes */;
    short deformflag /* 2 bytes */;
    short pathflag /* 2 bytes */;
    int layer_used /* 4 bytes */;
    int layer /* 4 bytes */;
    int layer_protected /* 4 bytes */;
    short ghostep /* 2 bytes */;
    short ghostsize /* 2 bytes */;
    short ghosttype /* 2 bytes */;
    short pathsize /* 2 bytes */;
    int ghostsf /* 4 bytes */;
    int ghostef /* 4 bytes */;
    int pathsf /* 4 bytes */;
    int pathef /* 4 bytes */;
    int pathbc /* 4 bytes */;
    int pathac /* 4 bytes */;
};

struct bMotionPathVert {
    float co[3] /* 12 bytes */;
    int flag /* 4 bytes */;
};

struct bMotionPath {
    bMotionPathVert *points /* 8 bytes */;
    int length /* 4 bytes */;
    int start_frame /* 4 bytes */;
    int end_frame /* 4 bytes */;
    int flag /* 4 bytes */;
};

struct bPoseChannel {
    bPoseChannel *next /* 8 bytes */;
    bPoseChannel *prev /* 8 bytes */;
    IDProperty *prop /* 8 bytes */;
    ListBase constraints /* 16 bytes */;
    char name[64] /* 64 bytes */;
    short flag /* 2 bytes */;
    short ikflag /* 2 bytes */;
    short protectflag /* 2 bytes */;
    short agrp_index /* 2 bytes */;
    char constflag /* 1 bytes */;
    char selectflag /* 1 bytes */;
    char pad0[6] /* 6 bytes */;
    Bone *bone /* 8 bytes */;
    bPoseChannel *parent /* 8 bytes */;
    bPoseChannel *child /* 8 bytes */;
    ListBase iktree /* 16 bytes */;
    ListBase siktree /* 16 bytes */;
    bMotionPath *mpath /* 8 bytes */;
    Object *custom /* 8 bytes */;
    bPoseChannel *custom_tx /* 8 bytes */;
    float loc[3] /* 12 bytes */;
    float size[3] /* 12 bytes */;
    float eul[3] /* 12 bytes */;
    float quat[4] /* 16 bytes */;
    float rotAxis[3] /* 12 bytes */;
    float rotAngle /* 4 bytes */;
    short rotmode /* 2 bytes */;
    short pad /* 2 bytes */;
    float chan_mat[4][4] /* 64 bytes */;
    float pose_mat[4][4] /* 64 bytes */;
    float constinv[4][4] /* 64 bytes */;
    float pose_head[3] /* 12 bytes */;
    float pose_tail[3] /* 12 bytes */;
    float limitmin[3] /* 12 bytes */;
    float limitmax[3] /* 12 bytes */;
    float stiffness[3] /* 12 bytes */;
    float ikstretch /* 4 bytes */;
    float ikrotweight /* 4 bytes */;
    float iklinweight /* 4 bytes */;
    void *temp /* 8 bytes */;
};

struct bPose {
    ListBase chanbase /* 16 bytes */;
    void *chanhash /* 8 bytes */;
    short flag /* 2 bytes */;
    short pad /* 2 bytes */;
    int proxy_layer /* 4 bytes */;
    int pad1 /* 4 bytes */;
    float ctime /* 4 bytes */;
    float stride_offset[3] /* 12 bytes */;
    float cyclic_offset[3] /* 12 bytes */;
    ListBase agroups /* 16 bytes */;
    int active_group /* 4 bytes */;
    int iksolver /* 4 bytes */;
    void *ikdata /* 8 bytes */;
    void *ikparam /* 8 bytes */;
    bAnimVizSettings avs /* 48 bytes */;
    char proxy_act_bone[64] /* 64 bytes */;
};

struct bIKParam {
    int iksolver /* 4 bytes */;
};

struct bItasc {
    int iksolver /* 4 bytes */;
    float precision /* 4 bytes */;
    short numiter /* 2 bytes */;
    short numstep /* 2 bytes */;
    float minstep /* 4 bytes */;
    float maxstep /* 4 bytes */;
    short solver /* 2 bytes */;
    short flag /* 2 bytes */;
    float feedback /* 4 bytes */;
    float maxvel /* 4 bytes */;
    float dampmax /* 4 bytes */;
    float dampeps /* 4 bytes */;
};

struct bActionGroup {
    bActionGroup *next /* 8 bytes */;
    bActionGroup *prev /* 8 bytes */;
    ListBase channels /* 16 bytes */;
    int flag /* 4 bytes */;
    int customCol /* 4 bytes */;
    char name[64] /* 64 bytes */;
    ThemeWireColor cs /* 16 bytes */;
};

struct bAction {
    ID id /* 120 bytes */;
    ListBase curves /* 16 bytes */;
    ListBase chanbase /* 16 bytes */;
    ListBase groups /* 16 bytes */;
    ListBase markers /* 16 bytes */;
    int flag /* 4 bytes */;
    int active_marker /* 4 bytes */;
    int idroot /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct bDopeSheet {
    ID *source /* 8 bytes */;
    ListBase chanbase /* 16 bytes */;
    Group *filter_grp /* 8 bytes */;
    char searchstr[64] /* 64 bytes */;
    int filterflag /* 4 bytes */;
    int flag /* 4 bytes */;
    int renameIndex /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct SpaceAction {
    SpaceLink *next /* 8 bytes */;
    SpaceLink *prev /* 8 bytes */;
    ListBase regionbase /* 16 bytes */;
    int spacetype /* 4 bytes */;
    float blockscale /* 4 bytes */;
    short blockhandler[8] /* 16 bytes */;
    View2D v2d /* 160 bytes */;
    bAction *action /* 8 bytes */;
    bDopeSheet ads /* 112 bytes */;
    char mode /* 1 bytes */;
    char autosnap /* 1 bytes */;
    short flag /* 2 bytes */;
    float timeslide /* 4 bytes */;
};

struct bActionChannel {
    bActionChannel *next /* 8 bytes */;
    bActionChannel *prev /* 8 bytes */;
    bActionGroup *grp /* 8 bytes */;
    Ipo *ipo /* 8 bytes */;
    ListBase constraintChannels /* 16 bytes */;
    int flag /* 4 bytes */;
    char name[64] /* 64 bytes */;
    int temp /* 4 bytes */;
};

struct bConstraintChannel {
    bConstraintChannel *next /* 8 bytes */;
    bConstraintChannel *prev /* 8 bytes */;
    Ipo *ipo /* 8 bytes */;
    short flag /* 2 bytes */;
    char name[30] /* 30 bytes */;
};

struct bConstraint {
    bConstraint *next /* 8 bytes */;
    bConstraint *prev /* 8 bytes */;
    void *data /* 8 bytes */;
    short type /* 2 bytes */;
    short flag /* 2 bytes */;
    char ownspace /* 1 bytes */;
    char tarspace /* 1 bytes */;
    char name[64] /* 64 bytes */;
    short pad /* 2 bytes */;
    float enforce /* 4 bytes */;
    float headtail /* 4 bytes */;
    Ipo *ipo /* 8 bytes */;
    float lin_error /* 4 bytes */;
    float rot_error /* 4 bytes */;
};

struct bConstraintTarget {
    bConstraintTarget *next /* 8 bytes */;
    bConstraintTarget *prev /* 8 bytes */;
    Object *tar /* 8 bytes */;
    char subtarget[64] /* 64 bytes */;
    float matrix[4][4] /* 64 bytes */;
    short space /* 2 bytes */;
    short flag /* 2 bytes */;
    short type /* 2 bytes */;
    short rotOrder /* 2 bytes */;
};

struct bPythonConstraint {
    Text *text /* 8 bytes */;
    IDProperty *prop /* 8 bytes */;
    int flag /* 4 bytes */;
    int tarnum /* 4 bytes */;
    ListBase targets /* 16 bytes */;
    Object *tar /* 8 bytes */;
    char subtarget[64] /* 64 bytes */;
};

struct bKinematicConstraint {
    Object *tar /* 8 bytes */;
    short iterations /* 2 bytes */;
    short flag /* 2 bytes */;
    short rootbone /* 2 bytes */;
    short max_rootbone /* 2 bytes */;
    char subtarget[64] /* 64 bytes */;
    Object *poletar /* 8 bytes */;
    char polesubtarget[64] /* 64 bytes */;
    float poleangle /* 4 bytes */;
    float weight /* 4 bytes */;
    float orientweight /* 4 bytes */;
    float grabtarget[3] /* 12 bytes */;
    short type /* 2 bytes */;
    short mode /* 2 bytes */;
    float dist /* 4 bytes */;
};

struct bSplineIKConstraint {
    Object *tar /* 8 bytes */;
    float *points /* 8 bytes */;
    short numpoints /* 2 bytes */;
    short chainlen /* 2 bytes */;
    short flag /* 2 bytes */;
    short xzScaleMode /* 2 bytes */;
    float bulge /* 4 bytes */;
    float bulge_min /* 4 bytes */;
    float bulge_max /* 4 bytes */;
    float bulge_smooth /* 4 bytes */;
};

struct bTrackToConstraint {
    Object *tar /* 8 bytes */;
    int reserved1 /* 4 bytes */;
    int reserved2 /* 4 bytes */;
    int flags /* 4 bytes */;
    int pad /* 4 bytes */;
    char subtarget[64] /* 64 bytes */;
};

struct bRotateLikeConstraint {
    Object *tar /* 8 bytes */;
    int flag /* 4 bytes */;
    int reserved1 /* 4 bytes */;
    char subtarget[64] /* 64 bytes */;
};

struct bLocateLikeConstraint {
    Object *tar /* 8 bytes */;
    int flag /* 4 bytes */;
    int reserved1 /* 4 bytes */;
    char subtarget[64] /* 64 bytes */;
};

struct bSizeLikeConstraint {
    Object *tar /* 8 bytes */;
    int flag /* 4 bytes */;
    int reserved1 /* 4 bytes */;
    char subtarget[64] /* 64 bytes */;
};

struct bSameVolumeConstraint {
    int flag /* 4 bytes */;
    float volume /* 4 bytes */;
};

struct bTransLikeConstraint {
    Object *tar /* 8 bytes */;
    char subtarget[64] /* 64 bytes */;
};

struct bMinMaxConstraint {
    Object *tar /* 8 bytes */;
    int minmaxflag /* 4 bytes */;
    float offset /* 4 bytes */;
    int flag /* 4 bytes */;
    short sticky /* 2 bytes */;
    short stuck /* 2 bytes */;
    short pad1 /* 2 bytes */;
    short pad2 /* 2 bytes */;
    float cache[3] /* 12 bytes */;
    char subtarget[64] /* 64 bytes */;
};

struct bActionConstraint {
    Object *tar /* 8 bytes */;
    short type /* 2 bytes */;
    short local /* 2 bytes */;
    int start /* 4 bytes */;
    int end /* 4 bytes */;
    float min /* 4 bytes */;
    float max /* 4 bytes */;
    int flag /* 4 bytes */;
    bAction *act /* 8 bytes */;
    char subtarget[64] /* 64 bytes */;
};

struct bLockTrackConstraint {
    Object *tar /* 8 bytes */;
    int trackflag /* 4 bytes */;
    int lockflag /* 4 bytes */;
    char subtarget[64] /* 64 bytes */;
};

struct bDampTrackConstraint {
    Object *tar /* 8 bytes */;
    int trackflag /* 4 bytes */;
    int pad /* 4 bytes */;
    char subtarget[64] /* 64 bytes */;
};

struct bFollowPathConstraint {
    Object *tar /* 8 bytes */;
    float offset /* 4 bytes */;
    float offset_fac /* 4 bytes */;
    int followflag /* 4 bytes */;
    short trackflag /* 2 bytes */;
    short upflag /* 2 bytes */;
};

struct bStretchToConstraint {
    Object *tar /* 8 bytes */;
    int flag /* 4 bytes */;
    int volmode /* 4 bytes */;
    int plane /* 4 bytes */;
    float orglength /* 4 bytes */;
    float bulge /* 4 bytes */;
    float bulge_min /* 4 bytes */;
    float bulge_max /* 4 bytes */;
    float bulge_smooth /* 4 bytes */;
    char subtarget[64] /* 64 bytes */;
};

struct bRigidBodyJointConstraint {
    Object *tar /* 8 bytes */;
    Object *child /* 8 bytes */;
    int type /* 4 bytes */;
    float pivX /* 4 bytes */;
    float pivY /* 4 bytes */;
    float pivZ /* 4 bytes */;
    float axX /* 4 bytes */;
    float axY /* 4 bytes */;
    float axZ /* 4 bytes */;
    float minLimit[6] /* 24 bytes */;
    float maxLimit[6] /* 24 bytes */;
    float extraFz /* 4 bytes */;
    short flag /* 2 bytes */;
    short pad /* 2 bytes */;
    short pad1 /* 2 bytes */;
    short pad2 /* 2 bytes */;
};

struct bClampToConstraint {
    Object *tar /* 8 bytes */;
    int flag /* 4 bytes */;
    int flag2 /* 4 bytes */;
};

struct bChildOfConstraint {
    Object *tar /* 8 bytes */;
    int flag /* 4 bytes */;
    int pad /* 4 bytes */;
    float invmat[4][4] /* 64 bytes */;
    char subtarget[64] /* 64 bytes */;
};

struct bTransformConstraint {
    Object *tar /* 8 bytes */;
    char subtarget[64] /* 64 bytes */;
    short from /* 2 bytes */;
    short to /* 2 bytes */;
    char map[3] /* 3 bytes */;
    char expo /* 1 bytes */;
    float from_min[3] /* 12 bytes */;
    float from_max[3] /* 12 bytes */;
    float to_min[3] /* 12 bytes */;
    float to_max[3] /* 12 bytes */;
    float from_min_rot[3] /* 12 bytes */;
    float from_max_rot[3] /* 12 bytes */;
    float to_min_rot[3] /* 12 bytes */;
    float to_max_rot[3] /* 12 bytes */;
    float from_min_scale[3] /* 12 bytes */;
    float from_max_scale[3] /* 12 bytes */;
    float to_min_scale[3] /* 12 bytes */;
    float to_max_scale[3] /* 12 bytes */;
};

struct bPivotConstraint {
    Object *tar /* 8 bytes */;
    char subtarget[64] /* 64 bytes */;
    float offset[3] /* 12 bytes */;
    short rotAxis /* 2 bytes */;
    short flag /* 2 bytes */;
};

struct bLocLimitConstraint {
    float xmin /* 4 bytes */;
    float xmax /* 4 bytes */;
    float ymin /* 4 bytes */;
    float ymax /* 4 bytes */;
    float zmin /* 4 bytes */;
    float zmax /* 4 bytes */;
    short flag /* 2 bytes */;
    short flag2 /* 2 bytes */;
};

struct bRotLimitConstraint {
    float xmin /* 4 bytes */;
    float xmax /* 4 bytes */;
    float ymin /* 4 bytes */;
    float ymax /* 4 bytes */;
    float zmin /* 4 bytes */;
    float zmax /* 4 bytes */;
    short flag /* 2 bytes */;
    short flag2 /* 2 bytes */;
};

struct bSizeLimitConstraint {
    float xmin /* 4 bytes */;
    float xmax /* 4 bytes */;
    float ymin /* 4 bytes */;
    float ymax /* 4 bytes */;
    float zmin /* 4 bytes */;
    float zmax /* 4 bytes */;
    short flag /* 2 bytes */;
    short flag2 /* 2 bytes */;
};

struct bDistLimitConstraint {
    Object *tar /* 8 bytes */;
    char subtarget[64] /* 64 bytes */;
    float dist /* 4 bytes */;
    float soft /* 4 bytes */;
    short flag /* 2 bytes */;
    short mode /* 2 bytes */;
    int pad /* 4 bytes */;
};

struct bShrinkwrapConstraint {
    Object *target /* 8 bytes */;
    float dist /* 4 bytes */;
    short shrinkType /* 2 bytes */;
    char projAxis /* 1 bytes */;
    char projAxisSpace /* 1 bytes */;
    float projLimit /* 4 bytes */;
    char pad[4] /* 4 bytes */;
};

struct bFollowTrackConstraint {
    MovieClip *clip /* 8 bytes */;
    char track[64] /* 64 bytes */;
    int flag /* 4 bytes */;
    int frame_method /* 4 bytes */;
    char object[64] /* 64 bytes */;
    Object *camera /* 8 bytes */;
    Object *depth_ob /* 8 bytes */;
};

struct bCameraSolverConstraint {
    MovieClip *clip /* 8 bytes */;
    int flag /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct bObjectSolverConstraint {
    MovieClip *clip /* 8 bytes */;
    int flag /* 4 bytes */;
    int pad /* 4 bytes */;
    char object[64] /* 64 bytes */;
    float invmat[4][4] /* 64 bytes */;
    Object *camera /* 8 bytes */;
};

struct bActionModifier {
    bActionModifier *next /* 8 bytes */;
    bActionModifier *prev /* 8 bytes */;
    short type /* 2 bytes */;
    short flag /* 2 bytes */;
    char channel[32] /* 32 bytes */;
    float noisesize /* 4 bytes */;
    float turbul /* 4 bytes */;
    short channels /* 2 bytes */;
    short no_rot_axis /* 2 bytes */;
    Object *ob /* 8 bytes */;
};

struct bActionStrip {
    bActionStrip *next /* 8 bytes */;
    bActionStrip *prev /* 8 bytes */;
    short flag /* 2 bytes */;
    short mode /* 2 bytes */;
    short stride_axis /* 2 bytes */;
    short curmod /* 2 bytes */;
    Ipo *ipo /* 8 bytes */;
    bAction *act /* 8 bytes */;
    Object *object /* 8 bytes */;
    float start /* 4 bytes */;
    float end /* 4 bytes */;
    float actstart /* 4 bytes */;
    float actend /* 4 bytes */;
    float actoffs /* 4 bytes */;
    float stridelen /* 4 bytes */;
    float repeat /* 4 bytes */;
    float scale /* 4 bytes */;
    float blendin /* 4 bytes */;
    float blendout /* 4 bytes */;
    char stridechannel[32] /* 32 bytes */;
    char offs_bone[32] /* 32 bytes */;
    ListBase modifiers /* 16 bytes */;
};

struct bNodeStack {
    float vec[4] /* 16 bytes */;
    float min /* 4 bytes */;
    float max /* 4 bytes */;
    void *data /* 8 bytes */;
    short hasinput /* 2 bytes */;
    short hasoutput /* 2 bytes */;
    short datatype /* 2 bytes */;
    short sockettype /* 2 bytes */;
    short is_copy /* 2 bytes */;
    short external /* 2 bytes */;
    short pad[2] /* 4 bytes */;
};

struct bNodeSocket {
    bNodeSocket *next /* 8 bytes */;
    bNodeSocket *prev /* 8 bytes */;
    bNodeSocket *new_sock /* 8 bytes */;
    IDProperty *prop /* 8 bytes */;
    char identifier[64] /* 64 bytes */;
    char name[64] /* 64 bytes */;
    void *storage /* 8 bytes */;
    short type /* 2 bytes */;
    short flag /* 2 bytes */;
    short limit /* 2 bytes */;
    short in_out /* 2 bytes */;
    void *typeinfo /* 8 bytes */;
    char idname[64] /* 64 bytes */;
    float locx /* 4 bytes */;
    float locy /* 4 bytes */;
    void *default_value /* 8 bytes */;
    short stack_index /* 2 bytes */;
    short stack_type /* 2 bytes */;
    int pad /* 4 bytes */;
    void *cache /* 8 bytes */;
    int own_index /* 4 bytes */;
    int to_index /* 4 bytes */;
    bNodeSocket *groupsock /* 8 bytes */;
    bNodeLink *link /* 8 bytes */;
    bNodeStack ns /* 48 bytes */;
};

struct bNode {
    bNode *next /* 8 bytes */;
    bNode *prev /* 8 bytes */;
    bNode *new_node /* 8 bytes */;
    IDProperty *prop /* 8 bytes */;
    void *typeinfo /* 8 bytes */;
    char idname[64] /* 64 bytes */;
    char name[64] /* 64 bytes */;
    int flag /* 4 bytes */;
    short type /* 2 bytes */;
    short pad /* 2 bytes */;
    short done /* 2 bytes */;
    short level /* 2 bytes */;
    short lasty /* 2 bytes */;
    short menunr /* 2 bytes */;
    short stack_index /* 2 bytes */;
    short nr /* 2 bytes */;
    float color[3] /* 12 bytes */;
    ListBase inputs /* 16 bytes */;
    ListBase outputs /* 16 bytes */;
    bNode *parent /* 8 bytes */;
    ID *id /* 8 bytes */;
    void *storage /* 8 bytes */;
    bNode *original /* 8 bytes */;
    ListBase internal_links /* 16 bytes */;
    float locx /* 4 bytes */;
    float locy /* 4 bytes */;
    float width /* 4 bytes */;
    float height /* 4 bytes */;
    float miniwidth /* 4 bytes */;
    float offsetx /* 4 bytes */;
    float offsety /* 4 bytes */;
    int update /* 4 bytes */;
    char label[64] /* 64 bytes */;
    short custom1 /* 2 bytes */;
    short custom2 /* 2 bytes */;
    float custom3 /* 4 bytes */;
    float custom4 /* 4 bytes */;
    short need_exec /* 2 bytes */;
    short exec /* 2 bytes */;
    void *threaddata /* 8 bytes */;
    rctf totr /* 16 bytes */;
    rctf butr /* 16 bytes */;
    rctf prvr /* 16 bytes */;
    short preview_xsize /* 2 bytes */;
    short preview_ysize /* 2 bytes */;
    int pad2 /* 4 bytes */;
    void *block /* 8 bytes */;
};

struct bNodeInstanceHashEntry {
    bNodeInstanceKey key /* 4 bytes */;
    short tag /* 2 bytes */;
    short pad /* 2 bytes */;
};

struct bNodePreview {
    bNodeInstanceHashEntry hash_entry /* 8 bytes */;
    char *rect /* 8 bytes */;
    short xsize /* 2 bytes */;
    short ysize /* 2 bytes */;
    int pad /* 4 bytes */;
};

struct bNodeLink {
    bNodeLink *next /* 8 bytes */;
    bNodeLink *prev /* 8 bytes */;
    bNode *fromnode /* 8 bytes */;
    bNode *tonode /* 8 bytes */;
    bNodeSocket *fromsock /* 8 bytes */;
    bNodeSocket *tosock /* 8 bytes */;
    int flag /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct bNodeTree {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
    void *typeinfo /* 8 bytes */;
    char idname[64] /* 64 bytes */;
    void *interface_type /* 8 bytes */;
    bGPdata *gpd /* 8 bytes */;
    float view_center[2] /* 8 bytes */;
    ListBase nodes /* 16 bytes */;
    ListBase links /* 16 bytes */;
    int type /* 4 bytes */;
    int init /* 4 bytes */;
    int cur_index /* 4 bytes */;
    int flag /* 4 bytes */;
    int update /* 4 bytes */;
    short is_updating /* 2 bytes */;
    short done /* 2 bytes */;
    int pad2 /* 4 bytes */;
    int nodetype /* 4 bytes */;
    short edit_quality /* 2 bytes */;
    short render_quality /* 2 bytes */;
    int chunksize /* 4 bytes */;
    rctf viewer_border /* 16 bytes */;
    ListBase inputs /* 16 bytes */;
    ListBase outputs /* 16 bytes */;
    void *previews /* 8 bytes */;
    bNodeInstanceKey active_viewer_key /* 4 bytes */;
    int pad /* 4 bytes */;
    void *execdata /* 8 bytes */;
    void (*progress)() /* 8 bytes */;
    void (*stats_draw)() /* 8 bytes */;
    int (*test_break)() /* 8 bytes */;
    void (*update_draw)() /* 8 bytes */;
    void *tbh /* 8 bytes */;
    void *prh /* 8 bytes */;
    void *sdh /* 8 bytes */;
    void *udh /* 8 bytes */;
};

struct bNodeSocketValueInt {
    int subtype /* 4 bytes */;
    int value /* 4 bytes */;
    int min /* 4 bytes */;
    int max /* 4 bytes */;
};

struct bNodeSocketValueFloat {
    int subtype /* 4 bytes */;
    float value /* 4 bytes */;
    float min /* 4 bytes */;
    float max /* 4 bytes */;
};

struct bNodeSocketValueBoolean {
    char value /* 1 bytes */;
    char pad[3] /* 3 bytes */;
};

struct bNodeSocketValueVector {
    int subtype /* 4 bytes */;
    float value[3] /* 12 bytes */;
    float min /* 4 bytes */;
    float max /* 4 bytes */;
};

struct bNodeSocketValueRGBA {
    float value[4] /* 16 bytes */;
};

struct bNodeSocketValueString {
    int subtype /* 4 bytes */;
    int pad /* 4 bytes */;
    char value[1024] /* 1024 bytes */;
};

struct NodeFrame {
    short flag /* 2 bytes */;
    short label_size /* 2 bytes */;
};

struct NodeImageAnim {
    int frames /* 4 bytes */;
    int sfra /* 4 bytes */;
    int nr /* 4 bytes */;
    char cyclic /* 1 bytes */;
    char movie /* 1 bytes */;
    short pad /* 2 bytes */;
};

struct ColorCorrectionData {
    float saturation /* 4 bytes */;
    float contrast /* 4 bytes */;
    float gamma /* 4 bytes */;
    float gain /* 4 bytes */;
    float lift /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct NodeColorCorrection {
    ColorCorrectionData master /* 24 bytes */;
    ColorCorrectionData shadows /* 24 bytes */;
    ColorCorrectionData midtones /* 24 bytes */;
    ColorCorrectionData highlights /* 24 bytes */;
    float startmidtones /* 4 bytes */;
    float endmidtones /* 4 bytes */;
};

struct NodeBokehImage {
    float angle /* 4 bytes */;
    int flaps /* 4 bytes */;
    float rounding /* 4 bytes */;
    float catadioptric /* 4 bytes */;
    float lensshift /* 4 bytes */;
};

struct NodeBoxMask {
    float x /* 4 bytes */;
    float y /* 4 bytes */;
    float rotation /* 4 bytes */;
    float height /* 4 bytes */;
    float width /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct NodeEllipseMask {
    float x /* 4 bytes */;
    float y /* 4 bytes */;
    float rotation /* 4 bytes */;
    float height /* 4 bytes */;
    float width /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct NodeImageLayer {
    int pass_index /* 4 bytes */;
    int pass_flag /* 4 bytes */;
};

struct NodeBlurData {
    short sizex /* 2 bytes */;
    short sizey /* 2 bytes */;
    short samples /* 2 bytes */;
    short maxspeed /* 2 bytes */;
    short minspeed /* 2 bytes */;
    short relative /* 2 bytes */;
    short aspect /* 2 bytes */;
    short curved /* 2 bytes */;
    float fac /* 4 bytes */;
    float percentx /* 4 bytes */;
    float percenty /* 4 bytes */;
    short filtertype /* 2 bytes */;
    char bokeh /* 1 bytes */;
    char gamma /* 1 bytes */;
    int image_in_width /* 4 bytes */;
    int image_in_height /* 4 bytes */;
};

struct NodeDBlurData {
    float center_x /* 4 bytes */;
    float center_y /* 4 bytes */;
    float distance /* 4 bytes */;
    float angle /* 4 bytes */;
    float spin /* 4 bytes */;
    float zoom /* 4 bytes */;
    short iter /* 2 bytes */;
    char wrap /* 1 bytes */;
    char pad /* 1 bytes */;
};

struct NodeBilateralBlurData {
    float sigma_color /* 4 bytes */;
    float sigma_space /* 4 bytes */;
    short iter /* 2 bytes */;
    short pad /* 2 bytes */;
};

struct NodeHueSat {
    float hue /* 4 bytes */;
    float sat /* 4 bytes */;
    float val /* 4 bytes */;
};

struct NodeImageFile {
    char name[1024] /* 1024 bytes */;
    ImageFormatData im_format /* 248 bytes */;
    int sfra /* 4 bytes */;
    int efra /* 4 bytes */;
};

struct NodeImageMultiFile {
    char base_path[1024] /* 1024 bytes */;
    ImageFormatData format /* 248 bytes */;
    int sfra /* 4 bytes */;
    int efra /* 4 bytes */;
    int active_input /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct NodeImageMultiFileSocket {
    short use_render_format /* 2 bytes */;
    short use_node_format /* 2 bytes */;
    int pad1 /* 4 bytes */;
    char path[1024] /* 1024 bytes */;
    ImageFormatData format /* 248 bytes */;
    char layer[30] /* 30 bytes */;
    char pad2[2] /* 2 bytes */;
};

struct NodeChroma {
    float t1 /* 4 bytes */;
    float t2 /* 4 bytes */;
    float t3 /* 4 bytes */;
    float fsize /* 4 bytes */;
    float fstrength /* 4 bytes */;
    float falpha /* 4 bytes */;
    float key[4] /* 16 bytes */;
    short algorithm /* 2 bytes */;
    short channel /* 2 bytes */;
};

struct NodeTwoXYs {
    short x1 /* 2 bytes */;
    short x2 /* 2 bytes */;
    short y1 /* 2 bytes */;
    short y2 /* 2 bytes */;
    float fac_x1 /* 4 bytes */;
    float fac_x2 /* 4 bytes */;
    float fac_y1 /* 4 bytes */;
    float fac_y2 /* 4 bytes */;
};

struct NodeTwoFloats {
    float x /* 4 bytes */;
    float y /* 4 bytes */;
};

struct NodeGeometry {
    char uvname[64] /* 64 bytes */;
    char colname[64] /* 64 bytes */;
};

struct NodeVertexCol {
    char name[64] /* 64 bytes */;
};

struct NodeDefocus {
    char bktype /* 1 bytes */;
    char pad_c1 /* 1 bytes */;
    char preview /* 1 bytes */;
    char gamco /* 1 bytes */;
    short samples /* 2 bytes */;
    short no_zbuf /* 2 bytes */;
    float fstop /* 4 bytes */;
    float maxblur /* 4 bytes */;
    float bthresh /* 4 bytes */;
    float scale /* 4 bytes */;
    float rotation /* 4 bytes */;
    float pad_f1 /* 4 bytes */;
};

struct NodeScriptDict {
    void *dict /* 8 bytes */;
    void *node /* 8 bytes */;
};

struct NodeGlare {
    char quality /* 1 bytes */;
    char type /* 1 bytes */;
    char iter /* 1 bytes */;
    char angle /* 1 bytes */;
    char pad_c1 /* 1 bytes */;
    char size /* 1 bytes */;
    char pad[2] /* 2 bytes */;
    float colmod /* 4 bytes */;
    float mix /* 4 bytes */;
    float threshold /* 4 bytes */;
    float fade /* 4 bytes */;
    float angle_ofs /* 4 bytes */;
    float pad_f1 /* 4 bytes */;
};

struct NodeTonemap {
    float key /* 4 bytes */;
    float offset /* 4 bytes */;
    float gamma /* 4 bytes */;
    float f /* 4 bytes */;
    float m /* 4 bytes */;
    float a /* 4 bytes */;
    float c /* 4 bytes */;
    int type /* 4 bytes */;
};

struct NodeLensDist {
    short jit /* 2 bytes */;
    short proj /* 2 bytes */;
    short fit /* 2 bytes */;
    short pad /* 2 bytes */;
};

struct NodeColorBalance {
    float slope[3] /* 12 bytes */;
    float offset[3] /* 12 bytes */;
    float power[3] /* 12 bytes */;
    float lift[3] /* 12 bytes */;
    float gamma[3] /* 12 bytes */;
    float gain[3] /* 12 bytes */;
};

struct NodeColorspill {
    short limchan /* 2 bytes */;
    short unspill /* 2 bytes */;
    float limscale /* 4 bytes */;
    float uspillr /* 4 bytes */;
    float uspillg /* 4 bytes */;
    float uspillb /* 4 bytes */;
};

struct NodeDilateErode {
    char falloff /* 1 bytes */;
    char pad[7] /* 7 bytes */;
};

struct NodeMask {
    int size_x /* 4 bytes */;
    int size_y /* 4 bytes */;
};

struct NodeTexBase {
    TexMapping tex_mapping /* 144 bytes */;
    ColorMapping color_mapping /* 824 bytes */;
};

struct NodeTexSky {
    NodeTexBase base /* 968 bytes */;
    int sky_model /* 4 bytes */;
    float sun_direction[3] /* 12 bytes */;
    float turbidity /* 4 bytes */;
    float ground_albedo /* 4 bytes */;
};

struct NodeTexImage {
    NodeTexBase base /* 968 bytes */;
    ImageUser iuser /* 40 bytes */;
    int color_space /* 4 bytes */;
    int projection /* 4 bytes */;
    float projection_blend /* 4 bytes */;
    int interpolation /* 4 bytes */;
};

struct NodeTexChecker {
    NodeTexBase base /* 968 bytes */;
};

struct NodeTexBrick {
    NodeTexBase base /* 968 bytes */;
    int offset_freq /* 4 bytes */;
    int squash_freq /* 4 bytes */;
    float offset /* 4 bytes */;
    float squash /* 4 bytes */;
};

struct NodeTexEnvironment {
    NodeTexBase base /* 968 bytes */;
    ImageUser iuser /* 40 bytes */;
    int color_space /* 4 bytes */;
    int projection /* 4 bytes */;
};

struct NodeTexGradient {
    NodeTexBase base /* 968 bytes */;
    int gradient_type /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct NodeTexNoise {
    NodeTexBase base /* 968 bytes */;
};

struct NodeTexVoronoi {
    NodeTexBase base /* 968 bytes */;
    int coloring /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct NodeTexMusgrave {
    NodeTexBase base /* 968 bytes */;
    int musgrave_type /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct NodeTexWave {
    NodeTexBase base /* 968 bytes */;
    int wave_type /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct NodeTexMagic {
    NodeTexBase base /* 968 bytes */;
    int depth /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct NodeShaderAttribute {
    char name[64] /* 64 bytes */;
};

struct NodeShaderVectTransform {
    int type /* 4 bytes */;
    int convert_from /* 4 bytes */;
    int convert_to /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct TexNodeOutput {
    char name[64] /* 64 bytes */;
};

struct NodeKeyingScreenData {
    char tracking_object[64] /* 64 bytes */;
};

struct NodeKeyingData {
    float screen_balance /* 4 bytes */;
    float despill_factor /* 4 bytes */;
    float despill_balance /* 4 bytes */;
    int edge_kernel_radius /* 4 bytes */;
    float edge_kernel_tolerance /* 4 bytes */;
    float clip_black /* 4 bytes */;
    float clip_white /* 4 bytes */;
    int dilate_distance /* 4 bytes */;
    int feather_distance /* 4 bytes */;
    int feather_falloff /* 4 bytes */;
    int blur_pre /* 4 bytes */;
    int blur_post /* 4 bytes */;
};

struct NodeTrackPosData {
    char tracking_object[64] /* 64 bytes */;
    char track_name[64] /* 64 bytes */;
};

struct NodeTranslateData {
    char wrap_axis /* 1 bytes */;
    char relative /* 1 bytes */;
    char pad[6] /* 6 bytes */;
};

struct NodePlaneTrackDeformData {
    char tracking_object[64] /* 64 bytes */;
    char plane_track_name[64] /* 64 bytes */;
    char flag /* 1 bytes */;
    char motion_blur_samples /* 1 bytes */;
    char pad[2] /* 2 bytes */;
    float motion_blur_shutter /* 4 bytes */;
};

struct NodeShaderScript {
    int mode /* 4 bytes */;
    int flag /* 4 bytes */;
    char filepath[1024] /* 1024 bytes */;
    char bytecode_hash[64] /* 64 bytes */;
    char *bytecode /* 8 bytes */;
};

struct NodeShaderTangent {
    int direction_type /* 4 bytes */;
    int axis /* 4 bytes */;
    char uv_map[64] /* 64 bytes */;
};

struct NodeShaderNormalMap {
    int space /* 4 bytes */;
    char uv_map[64] /* 64 bytes */;
};

struct NodeShaderUVMap {
    char uv_map[64] /* 64 bytes */;
};

struct NodeSunBeams {
    float source[2] /* 8 bytes */;
    float ray_length /* 4 bytes */;
};

struct CurveMapPoint {
    float x /* 4 bytes */;
    float y /* 4 bytes */;
    short flag /* 2 bytes */;
    short shorty /* 2 bytes */;
};

struct BrushClone {
    Image *image /* 8 bytes */;
    float offset[2] /* 8 bytes */;
    float alpha /* 4 bytes */;
    float pad /* 4 bytes */;
};

struct Brush {
    ID id /* 120 bytes */;
    BrushClone clone /* 24 bytes */;
    CurveMapping *curve /* 8 bytes */;
    MTex mtex /* 320 bytes */;
    MTex mask_mtex /* 320 bytes */;
    Brush *toggle_brush /* 8 bytes */;
    void *icon_imbuf /* 8 bytes */;
    PreviewImage *preview /* 8 bytes */;
    ColorBand *gradient /* 8 bytes */;
    PaintCurve *paint_curve /* 8 bytes */;
    char icon_filepath[1024] /* 1024 bytes */;
    float normal_weight /* 4 bytes */;
    short blend /* 2 bytes */;
    short ob_mode /* 2 bytes */;
    float weight /* 4 bytes */;
    int size /* 4 bytes */;
    int flag /* 4 bytes */;
    int mask_pressure /* 4 bytes */;
    float jitter /* 4 bytes */;
    int jitter_absolute /* 4 bytes */;
    int overlay_flags /* 4 bytes */;
    int spacing /* 4 bytes */;
    int smooth_stroke_radius /* 4 bytes */;
    float smooth_stroke_factor /* 4 bytes */;
    float rate /* 4 bytes */;
    float rgb[3] /* 12 bytes */;
    float alpha /* 4 bytes */;
    float secondary_rgb[3] /* 12 bytes */;
    int sculpt_plane /* 4 bytes */;
    float plane_offset /* 4 bytes */;
    int flag2 /* 4 bytes */;
    int gradient_spacing /* 4 bytes */;
    int gradient_stroke_mode /* 4 bytes */;
    int gradient_fill_mode /* 4 bytes */;
    char sculpt_tool /* 1 bytes */;
    char vertexpaint_tool /* 1 bytes */;
    char imagepaint_tool /* 1 bytes */;
    char mask_tool /* 1 bytes */;
    float autosmooth_factor /* 4 bytes */;
    float crease_pinch_factor /* 4 bytes */;
    float plane_trim /* 4 bytes */;
    float height /* 4 bytes */;
    float texture_sample_bias /* 4 bytes */;
    int texture_overlay_alpha /* 4 bytes */;
    int mask_overlay_alpha /* 4 bytes */;
    int cursor_overlay_alpha /* 4 bytes */;
    float unprojected_radius /* 4 bytes */;
    float sharp_threshold /* 4 bytes */;
    int blur_kernel_radius /* 4 bytes */;
    int blur_mode /* 4 bytes */;
    float fill_threshold /* 4 bytes */;
    float add_col[3] /* 12 bytes */;
    float sub_col[3] /* 12 bytes */;
    float stencil_pos[2] /* 8 bytes */;
    float stencil_dimension[2] /* 8 bytes */;
    float mask_stencil_pos[2] /* 8 bytes */;
    float mask_stencil_dimension[2] /* 8 bytes */;
};

struct PaletteColor {
    PaletteColor *next /* 8 bytes */;
    PaletteColor *prev /* 8 bytes */;
    float rgb[3] /* 12 bytes */;
    float value /* 4 bytes */;
};

struct Palette {
    ID id /* 120 bytes */;
    ListBase colors /* 16 bytes */;
    ListBase deleted /* 16 bytes */;
    int active_color /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct PaintCurvePoint {
    BezTriple bez /* 72 bytes */;
    float pressure /* 4 bytes */;
};

struct PaintCurve {
    ID id /* 120 bytes */;
    PaintCurvePoint *points /* 8 bytes */;
    int tot_points /* 4 bytes */;
    int add_index /* 4 bytes */;
};

struct HairKey {
    float co[3] /* 12 bytes */;
    float time /* 4 bytes */;
    float weight /* 4 bytes */;
    short editflag /* 2 bytes */;
    short pad /* 2 bytes */;
    float world_co[3] /* 12 bytes */;
};

struct ParticleKey {
    float co[3] /* 12 bytes */;
    float vel[3] /* 12 bytes */;
    float rot[4] /* 16 bytes */;
    float ave[3] /* 12 bytes */;
    float time /* 4 bytes */;
};

struct BoidData {
    float health /* 4 bytes */;
    float acc[3] /* 12 bytes */;
    short state_id /* 2 bytes */;
    short mode /* 2 bytes */;
};

struct BoidParticle {
    Object *ground /* 8 bytes */;
    BoidData data /* 20 bytes */;
    float gravity[3] /* 12 bytes */;
    float wander[3] /* 12 bytes */;
    float rt /* 4 bytes */;
};

struct ParticleSpring {
    float rest_length /* 4 bytes */;
    int particle_index[2] /* 8 bytes */;
    int delete_flag /* 4 bytes */;
};

struct ChildParticle {
    int num /* 4 bytes */;
    int parent /* 4 bytes */;
    int pa[4] /* 16 bytes */;
    float w[4] /* 16 bytes */;
    float fuv[4] /* 16 bytes */;
    float foffset /* 4 bytes */;
    float rt /* 4 bytes */;
};

struct ParticleTarget {
    ParticleTarget *next /* 8 bytes */;
    ParticleTarget *prev /* 8 bytes */;
    Object *ob /* 8 bytes */;
    int psys /* 4 bytes */;
    short flag /* 2 bytes */;
    short mode /* 2 bytes */;
    float time /* 4 bytes */;
    float duration /* 4 bytes */;
};

struct ParticleDupliWeight {
    ParticleDupliWeight *next /* 8 bytes */;
    ParticleDupliWeight *prev /* 8 bytes */;
    Object *ob /* 8 bytes */;
    short count /* 2 bytes */;
    short flag /* 2 bytes */;
    short index /* 2 bytes */;
    short rt /* 2 bytes */;
};

struct ParticleData {
    ParticleKey state /* 56 bytes */;
    ParticleKey prev_state /* 56 bytes */;
    HairKey *hair /* 8 bytes */;
    ParticleKey *keys /* 8 bytes */;
    BoidParticle *boid /* 8 bytes */;
    int totkey /* 4 bytes */;
    float time /* 4 bytes */;
    float lifetime /* 4 bytes */;
    float dietime /* 4 bytes */;
    int num /* 4 bytes */;
    int num_dmcache /* 4 bytes */;
    float fuv[4] /* 16 bytes */;
    float foffset /* 4 bytes */;
    float size /* 4 bytes */;
    float sphdensity /* 4 bytes */;
    int pad /* 4 bytes */;
    int hair_index /* 4 bytes */;
    short flag /* 2 bytes */;
    short alive /* 2 bytes */;
};

struct SPHFluidSettings {
    float radius /* 4 bytes */;
    float spring_k /* 4 bytes */;
    float rest_length /* 4 bytes */;
    float plasticity_constant /* 4 bytes */;
    float yield_ratio /* 4 bytes */;
    float plasticity_balance /* 4 bytes */;
    float yield_balance /* 4 bytes */;
    float viscosity_omega /* 4 bytes */;
    float viscosity_beta /* 4 bytes */;
    float stiffness_k /* 4 bytes */;
    float stiffness_knear /* 4 bytes */;
    float rest_density /* 4 bytes */;
    float buoyancy /* 4 bytes */;
    int flag /* 4 bytes */;
    int spring_frames /* 4 bytes */;
    short solver /* 2 bytes */;
    short pad[3] /* 6 bytes */;
};

struct ParticleSettings {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
    BoidSettings *boids /* 8 bytes */;
    SPHFluidSettings *fluid /* 8 bytes */;
    EffectorWeights *effector_weights /* 8 bytes */;
    int flag /* 4 bytes */;
    int rt /* 4 bytes */;
    short type /* 2 bytes */;
    short from /* 2 bytes */;
    short distr /* 2 bytes */;
    short texact /* 2 bytes */;
    short phystype /* 2 bytes */;
    short rotmode /* 2 bytes */;
    short avemode /* 2 bytes */;
    short reactevent /* 2 bytes */;
    int draw /* 4 bytes */;
    int pad1 /* 4 bytes */;
    short draw_as /* 2 bytes */;
    short draw_size /* 2 bytes */;
    short childtype /* 2 bytes */;
    short pad2 /* 2 bytes */;
    short ren_as /* 2 bytes */;
    short subframes /* 2 bytes */;
    short draw_col /* 2 bytes */;
    short draw_step /* 2 bytes */;
    short ren_step /* 2 bytes */;
    short hair_step /* 2 bytes */;
    short keys_step /* 2 bytes */;
    short adapt_angle /* 2 bytes */;
    short adapt_pix /* 2 bytes */;
    short disp /* 2 bytes */;
    short omat /* 2 bytes */;
    short interpolation /* 2 bytes */;
    short integrator /* 2 bytes */;
    short rotfrom /* 2 bytes */;
    short kink /* 2 bytes */;
    short kink_axis /* 2 bytes */;
    short bb_align /* 2 bytes */;
    short bb_uv_split /* 2 bytes */;
    short bb_anim /* 2 bytes */;
    short bb_split_offset /* 2 bytes */;
    float bb_tilt /* 4 bytes */;
    float bb_rand_tilt /* 4 bytes */;
    float bb_offset[2] /* 8 bytes */;
    float bb_size[2] /* 8 bytes */;
    float bb_vel_head /* 4 bytes */;
    float bb_vel_tail /* 4 bytes */;
    float color_vec_max /* 4 bytes */;
    short simplify_flag /* 2 bytes */;
    short simplify_refsize /* 2 bytes */;
    float simplify_rate /* 4 bytes */;
    float simplify_transition /* 4 bytes */;
    float simplify_viewport /* 4 bytes */;
    float sta /* 4 bytes */;
    float end /* 4 bytes */;
    float lifetime /* 4 bytes */;
    float randlife /* 4 bytes */;
    float timetweak /* 4 bytes */;
    float courant_target /* 4 bytes */;
    float jitfac /* 4 bytes */;
    float eff_hair /* 4 bytes */;
    float grid_rand /* 4 bytes */;
    float ps_offset[1] /* 4 bytes */;
    int totpart /* 4 bytes */;
    int userjit /* 4 bytes */;
    int grid_res /* 4 bytes */;
    int effector_amount /* 4 bytes */;
    short time_flag /* 2 bytes */;
    short time_pad[3] /* 6 bytes */;
    float normfac /* 4 bytes */;
    float obfac /* 4 bytes */;
    float randfac /* 4 bytes */;
    float partfac /* 4 bytes */;
    float tanfac /* 4 bytes */;
    float tanphase /* 4 bytes */;
    float reactfac /* 4 bytes */;
    float ob_vel[3] /* 12 bytes */;
    float avefac /* 4 bytes */;
    float phasefac /* 4 bytes */;
    float randrotfac /* 4 bytes */;
    float randphasefac /* 4 bytes */;
    float mass /* 4 bytes */;
    float size /* 4 bytes */;
    float randsize /* 4 bytes */;
    float acc[3] /* 12 bytes */;
    float dragfac /* 4 bytes */;
    float brownfac /* 4 bytes */;
    float dampfac /* 4 bytes */;
    float randlength /* 4 bytes */;
    int child_flag /* 4 bytes */;
    int pad3 /* 4 bytes */;
    int child_nbr /* 4 bytes */;
    int ren_child_nbr /* 4 bytes */;
    float parents /* 4 bytes */;
    float childsize /* 4 bytes */;
    float childrandsize /* 4 bytes */;
    float childrad /* 4 bytes */;
    float childflat /* 4 bytes */;
    float clumpfac /* 4 bytes */;
    float clumppow /* 4 bytes */;
    float kink_amp /* 4 bytes */;
    float kink_freq /* 4 bytes */;
    float kink_shape /* 4 bytes */;
    float kink_flat /* 4 bytes */;
    float kink_amp_clump /* 4 bytes */;
    int kink_extra_steps /* 4 bytes */;
    int pad4 /* 4 bytes */;
    float kink_axis_random /* 4 bytes */;
    float kink_amp_random /* 4 bytes */;
    float rough1 /* 4 bytes */;
    float rough1_size /* 4 bytes */;
    float rough2 /* 4 bytes */;
    float rough2_size /* 4 bytes */;
    float rough2_thres /* 4 bytes */;
    float rough_end /* 4 bytes */;
    float rough_end_shape /* 4 bytes */;
    float clength /* 4 bytes */;
    float clength_thres /* 4 bytes */;
    float parting_fac /* 4 bytes */;
    float parting_min /* 4 bytes */;
    float parting_max /* 4 bytes */;
    float branch_thres /* 4 bytes */;
    float draw_line[2] /* 8 bytes */;
    float path_start /* 4 bytes */;
    float path_end /* 4 bytes */;
    int trail_count /* 4 bytes */;
    int keyed_loops /* 4 bytes */;
    CurveMapping *clumpcurve /* 8 bytes */;
    CurveMapping *roughcurve /* 8 bytes */;
    float clump_noise_size /* 4 bytes */;
    float bending_random /* 4 bytes */;
    MTex *mtex[18] /* 144 bytes */;
    Group *dup_group /* 8 bytes */;
    ListBase dupliweights /* 16 bytes */;
    Group *eff_group /* 8 bytes */;
    Object *dup_ob /* 8 bytes */;
    Object *bb_ob /* 8 bytes */;
    Ipo *ipo /* 8 bytes */;
    PartDeflect *pd /* 8 bytes */;
    PartDeflect *pd2 /* 8 bytes */;
    short use_modifier_stack /* 2 bytes */;
    short pad5[3] /* 6 bytes */;
};

struct ParticleSystem {
    ParticleSystem *next /* 8 bytes */;
    ParticleSystem *prev /* 8 bytes */;
    ParticleSettings *part /* 8 bytes */;
    ParticleData *particles /* 8 bytes */;
    ChildParticle *child /* 8 bytes */;
    void *edit /* 8 bytes */;
    void (*free_edit)() /* 8 bytes */;
    void **pathcache /* 8 bytes */;
    void **childcache /* 8 bytes */;
    ListBase pathcachebufs /* 16 bytes */;
    ListBase childcachebufs /* 16 bytes */;
    ClothModifierData *clmd /* 8 bytes */;
    void *hair_in_dm /* 8 bytes */;
    void *hair_out_dm /* 8 bytes */;
    Object *target_ob /* 8 bytes */;
    void *lattice_deform_data /* 8 bytes */;
    Object *parent /* 8 bytes */;
    ListBase targets /* 16 bytes */;
    char name[64] /* 64 bytes */;
    float imat[4][4] /* 64 bytes */;
    float cfra /* 4 bytes */;
    float tree_frame /* 4 bytes */;
    float bvhtree_frame /* 4 bytes */;
    int seed /* 4 bytes */;
    int child_seed /* 4 bytes */;
    int flag /* 4 bytes */;
    int totpart /* 4 bytes */;
    int totunexist /* 4 bytes */;
    int totchild /* 4 bytes */;
    int totcached /* 4 bytes */;
    int totchildcache /* 4 bytes */;
    short recalc /* 2 bytes */;
    short target_psys /* 2 bytes */;
    short totkeyed /* 2 bytes */;
    short bakespace /* 2 bytes */;
    char bb_uvname[3][64] /* 192 bytes */;
    short vgroup[12] /* 24 bytes */;
    short vg_neg /* 2 bytes */;
    short rt3 /* 2 bytes */;
    void *renderdata /* 8 bytes */;
    PointCache *pointcache /* 8 bytes */;
    ListBase ptcaches /* 16 bytes */;
    ListBase *effectors /* 8 bytes */;
    ParticleSpring *fluid_springs /* 8 bytes */;
    int tot_fluidsprings /* 4 bytes */;
    int alloc_fluidsprings /* 4 bytes */;
    void *tree /* 8 bytes */;
    void *bvhtree /* 8 bytes */;
    void *pdd /* 8 bytes */;
    float dt_frac /* 4 bytes */;
    float _pad /* 4 bytes */;
};

struct ClothSimSettings {
    void *cache /* 8 bytes */;
    float mingoal /* 4 bytes */;
    float Cdis /* 4 bytes */;
    float Cvi /* 4 bytes */;
    float gravity[3] /* 12 bytes */;
    float dt /* 4 bytes */;
    float mass /* 4 bytes */;
    float structural /* 4 bytes */;
    float shear /* 4 bytes */;
    float bending /* 4 bytes */;
    float max_bend /* 4 bytes */;
    float max_struct /* 4 bytes */;
    float max_shear /* 4 bytes */;
    float max_sewing /* 4 bytes */;
    float avg_spring_len /* 4 bytes */;
    float timescale /* 4 bytes */;
    float maxgoal /* 4 bytes */;
    float eff_force_scale /* 4 bytes */;
    float eff_wind_scale /* 4 bytes */;
    float sim_time_old /* 4 bytes */;
    float defgoal /* 4 bytes */;
    float goalspring /* 4 bytes */;
    float goalfrict /* 4 bytes */;
    float velocity_smooth /* 4 bytes */;
    float density_target /* 4 bytes */;
    float density_strength /* 4 bytes */;
    float collider_friction /* 4 bytes */;
    float vel_damping /* 4 bytes */;
    float shrink_min /* 4 bytes */;
    float shrink_max /* 4 bytes */;
    float bending_damping /* 4 bytes */;
    float voxel_cell_size /* 4 bytes */;
    int pad /* 4 bytes */;
    int stepsPerFrame /* 4 bytes */;
    int flags /* 4 bytes */;
    int preroll /* 4 bytes */;
    int maxspringlen /* 4 bytes */;
    short solver_type /* 2 bytes */;
    short vgroup_bend /* 2 bytes */;
    short vgroup_mass /* 2 bytes */;
    short vgroup_struct /* 2 bytes */;
    short vgroup_shrink /* 2 bytes */;
    short shapekey_rest /* 2 bytes */;
    short presets /* 2 bytes */;
    short reset /* 2 bytes */;
    EffectorWeights *effector_weights /* 8 bytes */;
};

struct ClothCollSettings {
    void *collision_list /* 8 bytes */;
    float epsilon /* 4 bytes */;
    float self_friction /* 4 bytes */;
    float friction /* 4 bytes */;
    float damping /* 4 bytes */;
    float selfepsilon /* 4 bytes */;
    float repel_force /* 4 bytes */;
    float distance_repel /* 4 bytes */;
    int flags /* 4 bytes */;
    short self_loop_count /* 2 bytes */;
    short loop_count /* 2 bytes */;
    int pad /* 4 bytes */;
    Group *group /* 8 bytes */;
    short vgroup_selfcol /* 2 bytes */;
    short pad2[3] /* 6 bytes */;
};

struct bGPDspoint {
    float x /* 4 bytes */;
    float y /* 4 bytes */;
    float z /* 4 bytes */;
    float pressure /* 4 bytes */;
    float time /* 4 bytes */;
    int flag /* 4 bytes */;
};

struct bGPDstroke {
    bGPDstroke *next /* 8 bytes */;
    bGPDstroke *prev /* 8 bytes */;
    bGPDspoint *points /* 8 bytes */;
    void *pad /* 8 bytes */;
    int totpoints /* 4 bytes */;
    short thickness /* 2 bytes */;
    short flag /* 2 bytes */;
    double inittime /* 8 bytes */;
};

struct bGPDframe {
    bGPDframe *next /* 8 bytes */;
    bGPDframe *prev /* 8 bytes */;
    ListBase strokes /* 16 bytes */;
    int framenum /* 4 bytes */;
    short flag /* 2 bytes */;
    short key_type /* 2 bytes */;
};

struct bGPDlayer {
    bGPDlayer *next /* 8 bytes */;
    bGPDlayer *prev /* 8 bytes */;
    ListBase frames /* 16 bytes */;
    bGPDframe *actframe /* 8 bytes */;
    short flag /* 2 bytes */;
    short thickness /* 2 bytes */;
    short gstep /* 2 bytes */;
    short gstep_next /* 2 bytes */;
    float gcolor_prev[3] /* 12 bytes */;
    float gcolor_next[3] /* 12 bytes */;
    float color[4] /* 16 bytes */;
    float fill[4] /* 16 bytes */;
    char info[128] /* 128 bytes */;
};

struct bGPdata {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
    ListBase layers /* 16 bytes */;
    int flag /* 4 bytes */;
    short sbuffer_size /* 2 bytes */;
    short sbuffer_sflag /* 2 bytes */;
    void *sbuffer /* 8 bytes */;
};

struct ReportList {
    ListBase list /* 16 bytes */;
    int printlevel /* 4 bytes */;
    int storelevel /* 4 bytes */;
    int flag /* 4 bytes */;
    int pad /* 4 bytes */;
    void *reporttimer /* 8 bytes */;
};

struct wmWindowManager {
    ID id /* 120 bytes */;
    wmWindow *windrawable /* 8 bytes */;
    wmWindow *winactive /* 8 bytes */;
    ListBase windows /* 16 bytes */;
    int initialized /* 4 bytes */;
    short file_saved /* 2 bytes */;
    short op_undo_depth /* 2 bytes */;
    ListBase operators /* 16 bytes */;
    ListBase queue /* 16 bytes */;
    ReportList reports /* 40 bytes */;
    ListBase jobs /* 16 bytes */;
    ListBase paintcursors /* 16 bytes */;
    ListBase drags /* 16 bytes */;
    ListBase keyconfigs /* 16 bytes */;
    wmKeyConfig *defaultconf /* 8 bytes */;
    wmKeyConfig *addonconf /* 8 bytes */;
    wmKeyConfig *userconf /* 8 bytes */;
    ListBase timers /* 16 bytes */;
    void *autosavetimer /* 8 bytes */;
    char is_interface_locked /* 1 bytes */;
    char par[7] /* 7 bytes */;
};

struct wmWindow {
    wmWindow *next /* 8 bytes */;
    wmWindow *prev /* 8 bytes */;
    void *ghostwin /* 8 bytes */;
    bScreen *screen /* 8 bytes */;
    bScreen *newscreen /* 8 bytes */;
    char screenname[64] /* 64 bytes */;
    short posx /* 2 bytes */;
    short posy /* 2 bytes */;
    short sizex /* 2 bytes */;
    short sizey /* 2 bytes */;
    short windowstate /* 2 bytes */;
    short monitor /* 2 bytes */;
    short active /* 2 bytes */;
    short cursor /* 2 bytes */;
    short lastcursor /* 2 bytes */;
    short modalcursor /* 2 bytes */;
    short grabcursor /* 2 bytes */;
    short addmousemove /* 2 bytes */;
    int winid /* 4 bytes */;
    short lock_pie_event /* 2 bytes */;
    short last_pie_event /* 2 bytes */;
    void *eventstate /* 8 bytes */;
    void *curswin /* 8 bytes */;
    void *tweak /* 8 bytes */;
    void *ime_data /* 8 bytes */;
    int drawmethod /* 4 bytes */;
    int drawfail /* 4 bytes */;
    void *drawdata /* 8 bytes */;
    ListBase queue /* 16 bytes */;
    ListBase handlers /* 16 bytes */;
    ListBase modalhandlers /* 16 bytes */;
    ListBase subwindows /* 16 bytes */;
    ListBase gesture /* 16 bytes */;
};

struct wmKeyMapItem {
    wmKeyMapItem *next /* 8 bytes */;
    wmKeyMapItem *prev /* 8 bytes */;
    char idname[64] /* 64 bytes */;
    IDProperty *properties /* 8 bytes */;
    char propvalue_str[64] /* 64 bytes */;
    short propvalue /* 2 bytes */;
    short type /* 2 bytes */;
    short val /* 2 bytes */;
    short shift /* 2 bytes */;
    short ctrl /* 2 bytes */;
    short alt /* 2 bytes */;
    short oskey /* 2 bytes */;
    short keymodifier /* 2 bytes */;
    short flag /* 2 bytes */;
    short maptype /* 2 bytes */;
    short id /* 2 bytes */;
    short pad /* 2 bytes */;
    void *ptr /* 8 bytes */;
};

struct wmKeyMapDiffItem {
    wmKeyMapDiffItem *next /* 8 bytes */;
    wmKeyMapDiffItem *prev /* 8 bytes */;
    wmKeyMapItem *remove_item /* 8 bytes */;
    wmKeyMapItem *add_item /* 8 bytes */;
};

struct wmKeyMap {
    wmKeyMap *next /* 8 bytes */;
    wmKeyMap *prev /* 8 bytes */;
    ListBase items /* 16 bytes */;
    ListBase diff_items /* 16 bytes */;
    char idname[64] /* 64 bytes */;
    short spaceid /* 2 bytes */;
    short regionid /* 2 bytes */;
    short flag /* 2 bytes */;
    short kmi_id /* 2 bytes */;
    int (*poll)() /* 8 bytes */;
    void *modal_items /* 8 bytes */;
};

struct wmKeyConfig {
    wmKeyConfig *next /* 8 bytes */;
    wmKeyConfig *prev /* 8 bytes */;
    char idname[64] /* 64 bytes */;
    char basename[64] /* 64 bytes */;
    ListBase keymaps /* 16 bytes */;
    int actkeymap /* 4 bytes */;
    int flag /* 4 bytes */;
};

struct wmOperator {
    wmOperator *next /* 8 bytes */;
    wmOperator *prev /* 8 bytes */;
    char idname[64] /* 64 bytes */;
    IDProperty *properties /* 8 bytes */;
    void *type /* 8 bytes */;
    void *customdata /* 8 bytes */;
    void *py_instance /* 8 bytes */;
    void *ptr /* 8 bytes */;
    ReportList *reports /* 8 bytes */;
    ListBase macro /* 16 bytes */;
    wmOperator *opm /* 8 bytes */;
    void *layout /* 8 bytes */;
    short flag /* 2 bytes */;
    short pad[3] /* 6 bytes */;
};

struct FModifier {
    FModifier *next /* 8 bytes */;
    FModifier *prev /* 8 bytes */;
    void *data /* 8 bytes */;
    char name[64] /* 64 bytes */;
    short type /* 2 bytes */;
    short flag /* 2 bytes */;
    float influence /* 4 bytes */;
    float sfra /* 4 bytes */;
    float efra /* 4 bytes */;
    float blendin /* 4 bytes */;
    float blendout /* 4 bytes */;
};

struct FMod_Generator {
    float *coefficients /* 8 bytes */;
    int arraysize /* 4 bytes */;
    int poly_order /* 4 bytes */;
    int mode /* 4 bytes */;
    int flag /* 4 bytes */;
};

struct FMod_FunctionGenerator {
    float amplitude /* 4 bytes */;
    float phase_multiplier /* 4 bytes */;
    float phase_offset /* 4 bytes */;
    float value_offset /* 4 bytes */;
    int type /* 4 bytes */;
    int flag /* 4 bytes */;
};

struct FCM_EnvelopeData {
    float min /* 4 bytes */;
    float max /* 4 bytes */;
    float time /* 4 bytes */;
    short f1 /* 2 bytes */;
    short f2 /* 2 bytes */;
};

struct FMod_Envelope {
    FCM_EnvelopeData *data /* 8 bytes */;
    int totvert /* 4 bytes */;
    float midval /* 4 bytes */;
    float min /* 4 bytes */;
    float max /* 4 bytes */;
};

struct FMod_Cycles {
    short before_mode /* 2 bytes */;
    short after_mode /* 2 bytes */;
    short before_cycles /* 2 bytes */;
    short after_cycles /* 2 bytes */;
};

struct FMod_Python {
    Text *script /* 8 bytes */;
    IDProperty *prop /* 8 bytes */;
};

struct FMod_Limits {
    rctf rect /* 16 bytes */;
    int flag /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct FMod_Noise {
    float size /* 4 bytes */;
    float strength /* 4 bytes */;
    float phase /* 4 bytes */;
    float offset /* 4 bytes */;
    short depth /* 2 bytes */;
    short modification /* 2 bytes */;
};

struct FMod_Stepped {
    float step_size /* 4 bytes */;
    float offset /* 4 bytes */;
    float start_frame /* 4 bytes */;
    float end_frame /* 4 bytes */;
    int flag /* 4 bytes */;
};

struct DriverTarget {
    ID *id /* 8 bytes */;
    char *rna_path /* 8 bytes */;
    char pchan_name[32] /* 32 bytes */;
    short transChan /* 2 bytes */;
    short flag /* 2 bytes */;
    int idtype /* 4 bytes */;
};

struct DriverVar {
    DriverVar *next /* 8 bytes */;
    DriverVar *prev /* 8 bytes */;
    char name[64] /* 64 bytes */;
    DriverTarget targets[8] /* 448 bytes */;
    short num_targets /* 2 bytes */;
    short type /* 2 bytes */;
    float curval /* 4 bytes */;
};

struct ChannelDriver {
    ListBase variables /* 16 bytes */;
    char expression[256] /* 256 bytes */;
    void *expr_comp /* 8 bytes */;
    float curval /* 4 bytes */;
    float influence /* 4 bytes */;
    int type /* 4 bytes */;
    int flag /* 4 bytes */;
};

struct FPoint {
    float vec[2] /* 8 bytes */;
    int flag /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct FCurve {
    FCurve *next /* 8 bytes */;
    FCurve *prev /* 8 bytes */;
    bActionGroup *grp /* 8 bytes */;
    ChannelDriver *driver /* 8 bytes */;
    ListBase modifiers /* 16 bytes */;
    BezTriple *bezt /* 8 bytes */;
    FPoint *fpt /* 8 bytes */;
    int totvert /* 4 bytes */;
    float curval /* 4 bytes */;
    short flag /* 2 bytes */;
    short extend /* 2 bytes */;
    int array_index /* 4 bytes */;
    char *rna_path /* 8 bytes */;
    int color_mode /* 4 bytes */;
    float color[3] /* 12 bytes */;
    float prev_norm_factor /* 4 bytes */;
    float pad /* 4 bytes */;
};

struct AnimMapPair {
    char from[128] /* 128 bytes */;
    char to[128] /* 128 bytes */;
};

struct AnimMapper {
    AnimMapper *next /* 8 bytes */;
    AnimMapper *prev /* 8 bytes */;
    bAction *target /* 8 bytes */;
    ListBase mappings /* 16 bytes */;
};

struct NlaStrip {
    NlaStrip *next /* 8 bytes */;
    NlaStrip *prev /* 8 bytes */;
    ListBase strips /* 16 bytes */;
    bAction *act /* 8 bytes */;
    AnimMapper *remap /* 8 bytes */;
    ListBase fcurves /* 16 bytes */;
    ListBase modifiers /* 16 bytes */;
    char name[64] /* 64 bytes */;
    float influence /* 4 bytes */;
    float strip_time /* 4 bytes */;
    float start /* 4 bytes */;
    float end /* 4 bytes */;
    float actstart /* 4 bytes */;
    float actend /* 4 bytes */;
    float repeat /* 4 bytes */;
    float scale /* 4 bytes */;
    float blendin /* 4 bytes */;
    float blendout /* 4 bytes */;
    short blendmode /* 2 bytes */;
    short extendmode /* 2 bytes */;
    short pad1 /* 2 bytes */;
    short type /* 2 bytes */;
    void *speaker_handle /* 8 bytes */;
    int flag /* 4 bytes */;
    int pad2 /* 4 bytes */;
};

struct NlaTrack {
    NlaTrack *next /* 8 bytes */;
    NlaTrack *prev /* 8 bytes */;
    ListBase strips /* 16 bytes */;
    int flag /* 4 bytes */;
    int index /* 4 bytes */;
    char name[64] /* 64 bytes */;
};

struct KS_Path {
    KS_Path *next /* 8 bytes */;
    KS_Path *prev /* 8 bytes */;
    ID *id /* 8 bytes */;
    char group[64] /* 64 bytes */;
    int idtype /* 4 bytes */;
    short groupmode /* 2 bytes */;
    short flag /* 2 bytes */;
    char *rna_path /* 8 bytes */;
    int array_index /* 4 bytes */;
    short keyingflag /* 2 bytes */;
    short keyingoverride /* 2 bytes */;
};

struct KeyingSet {
    KeyingSet *next /* 8 bytes */;
    KeyingSet *prev /* 8 bytes */;
    ListBase paths /* 16 bytes */;
    char idname[64] /* 64 bytes */;
    char name[64] /* 64 bytes */;
    char description[240] /* 240 bytes */;
    char typeinfo[64] /* 64 bytes */;
    int active_path /* 4 bytes */;
    short flag /* 2 bytes */;
    short keyingflag /* 2 bytes */;
    short keyingoverride /* 2 bytes */;
    char pad[6] /* 6 bytes */;
};

struct AnimOverride {
    AnimOverride *next /* 8 bytes */;
    AnimOverride *prev /* 8 bytes */;
    char *rna_path /* 8 bytes */;
    int array_index /* 4 bytes */;
    float value /* 4 bytes */;
};

struct AnimData {
    bAction *action /* 8 bytes */;
    bAction *tmpact /* 8 bytes */;
    AnimMapper *remap /* 8 bytes */;
    ListBase nla_tracks /* 16 bytes */;
    NlaStrip *actstrip /* 8 bytes */;
    ListBase drivers /* 16 bytes */;
    ListBase overrides /* 16 bytes */;
    int flag /* 4 bytes */;
    int recalc /* 4 bytes */;
    short act_blendmode /* 2 bytes */;
    short act_extendmode /* 2 bytes */;
    float act_influence /* 4 bytes */;
};

struct IdAdtTemplate {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
};

struct BoidRule {
    BoidRule *next /* 8 bytes */;
    BoidRule *prev /* 8 bytes */;
    int type /* 4 bytes */;
    int flag /* 4 bytes */;
    char name[32] /* 32 bytes */;
};

struct BoidRuleGoalAvoid {
    BoidRule rule /* 56 bytes */;
    Object *ob /* 8 bytes */;
    int options /* 4 bytes */;
    float fear_factor /* 4 bytes */;
    int signal_id /* 4 bytes */;
    int channels /* 4 bytes */;
};

struct BoidRuleAvoidCollision {
    BoidRule rule /* 56 bytes */;
    int options /* 4 bytes */;
    float look_ahead /* 4 bytes */;
};

struct BoidRuleFollowLeader {
    BoidRule rule /* 56 bytes */;
    Object *ob /* 8 bytes */;
    float loc[3] /* 12 bytes */;
    float oloc[3] /* 12 bytes */;
    float cfra /* 4 bytes */;
    float distance /* 4 bytes */;
    int options /* 4 bytes */;
    int queue_size /* 4 bytes */;
};

struct BoidRuleAverageSpeed {
    BoidRule rule /* 56 bytes */;
    float wander /* 4 bytes */;
    float level /* 4 bytes */;
    float speed /* 4 bytes */;
    float rt /* 4 bytes */;
};

struct BoidRuleFight {
    BoidRule rule /* 56 bytes */;
    float distance /* 4 bytes */;
    float flee_distance /* 4 bytes */;
};

struct BoidState {
    BoidState *next /* 8 bytes */;
    BoidState *prev /* 8 bytes */;
    ListBase rules /* 16 bytes */;
    ListBase conditions /* 16 bytes */;
    ListBase actions /* 16 bytes */;
    char name[32] /* 32 bytes */;
    int id /* 4 bytes */;
    int flag /* 4 bytes */;
    int ruleset_type /* 4 bytes */;
    float rule_fuzziness /* 4 bytes */;
    int signal_id /* 4 bytes */;
    int channels /* 4 bytes */;
    float volume /* 4 bytes */;
    float falloff /* 4 bytes */;
};

struct BoidSettings {
    int options /* 4 bytes */;
    int last_state_id /* 4 bytes */;
    float landing_smoothness /* 4 bytes */;
    float height /* 4 bytes */;
    float banking /* 4 bytes */;
    float pitch /* 4 bytes */;
    float health /* 4 bytes */;
    float aggression /* 4 bytes */;
    float strength /* 4 bytes */;
    float accuracy /* 4 bytes */;
    float range /* 4 bytes */;
    float air_min_speed /* 4 bytes */;
    float air_max_speed /* 4 bytes */;
    float air_max_acc /* 4 bytes */;
    float air_max_ave /* 4 bytes */;
    float air_personal_space /* 4 bytes */;
    float land_jump_speed /* 4 bytes */;
    float land_max_speed /* 4 bytes */;
    float land_max_acc /* 4 bytes */;
    float land_max_ave /* 4 bytes */;
    float land_personal_space /* 4 bytes */;
    float land_stick_force /* 4 bytes */;
    ListBase states /* 16 bytes */;
};

struct SmokeDomainSettings {
    SmokeModifierData *smd /* 8 bytes */;
    void *fluid /* 8 bytes */;
    void *fluid_mutex /* 8 bytes */;
    Group *fluid_group /* 8 bytes */;
    Group *eff_group /* 8 bytes */;
    Group *coll_group /* 8 bytes */;
    void *wt /* 8 bytes */;
    void *tex /* 8 bytes */;
    void *tex_wt /* 8 bytes */;
    void *tex_shadow /* 8 bytes */;
    void *tex_flame /* 8 bytes */;
    float *shadow /* 8 bytes */;
    float p0[3] /* 12 bytes */;
    float p1[3] /* 12 bytes */;
    float dp0[3] /* 12 bytes */;
    float cell_size[3] /* 12 bytes */;
    float global_size[3] /* 12 bytes */;
    float prev_loc[3] /* 12 bytes */;
    int shift[3] /* 12 bytes */;
    float shift_f[3] /* 12 bytes */;
    float obj_shift_f[3] /* 12 bytes */;
    float imat[4][4] /* 64 bytes */;
    float obmat[4][4] /* 64 bytes */;
    int base_res[3] /* 12 bytes */;
    int res_min[3] /* 12 bytes */;
    int res_max[3] /* 12 bytes */;
    int res[3] /* 12 bytes */;
    int total_cells /* 4 bytes */;
    float dx /* 4 bytes */;
    float scale /* 4 bytes */;
    int adapt_margin /* 4 bytes */;
    int adapt_res /* 4 bytes */;
    float adapt_threshold /* 4 bytes */;
    float alpha /* 4 bytes */;
    float beta /* 4 bytes */;
    int amplify /* 4 bytes */;
    int maxres /* 4 bytes */;
    int flags /* 4 bytes */;
    int viewsettings /* 4 bytes */;
    short noise /* 2 bytes */;
    short diss_percent /* 2 bytes */;
    int diss_speed /* 4 bytes */;
    float strength /* 4 bytes */;
    int res_wt[3] /* 12 bytes */;
    float dx_wt /* 4 bytes */;
    int cache_comp /* 4 bytes */;
    int cache_high_comp /* 4 bytes */;
    PointCache *point_cache[2] /* 16 bytes */;
    ListBase ptcaches[2] /* 32 bytes */;
    EffectorWeights *effector_weights /* 8 bytes */;
    int border_collisions /* 4 bytes */;
    float time_scale /* 4 bytes */;
    float vorticity /* 4 bytes */;
    int active_fields /* 4 bytes */;
    float active_color[3] /* 12 bytes */;
    int highres_sampling /* 4 bytes */;
    float burning_rate /* 4 bytes */;
    float flame_smoke /* 4 bytes */;
    float flame_vorticity /* 4 bytes */;
    float flame_ignition /* 4 bytes */;
    float flame_max_temp /* 4 bytes */;
    float flame_smoke_color[3] /* 12 bytes */;
};

struct SmokeFlowSettings {
    SmokeModifierData *smd /* 8 bytes */;
    void *dm /* 8 bytes */;
    ParticleSystem *psys /* 8 bytes */;
    Tex *noise_texture /* 8 bytes */;
    float *verts_old /* 8 bytes */;
    int numverts /* 4 bytes */;
    float vel_multi /* 4 bytes */;
    float vel_normal /* 4 bytes */;
    float vel_random /* 4 bytes */;
    float density /* 4 bytes */;
    float color[3] /* 12 bytes */;
    float fuel_amount /* 4 bytes */;
    float temp /* 4 bytes */;
    float volume_density /* 4 bytes */;
    float surface_distance /* 4 bytes */;
    float particle_size /* 4 bytes */;
    int subframes /* 4 bytes */;
    float texture_size /* 4 bytes */;
    float texture_offset /* 4 bytes */;
    int pad /* 4 bytes */;
    char uvlayer_name[64] /* 64 bytes */;
    short vgroup_density /* 2 bytes */;
    short type /* 2 bytes */;
    short source /* 2 bytes */;
    short texture_type /* 2 bytes */;
    int flags /* 4 bytes */;
};

struct SmokeCollSettings {
    SmokeModifierData *smd /* 8 bytes */;
    void *dm /* 8 bytes */;
    float *verts_old /* 8 bytes */;
    int numverts /* 4 bytes */;
    short type /* 2 bytes */;
    short pad /* 2 bytes */;
};

struct Speaker {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
    bSound *sound /* 8 bytes */;
    float volume_max /* 4 bytes */;
    float volume_min /* 4 bytes */;
    float distance_max /* 4 bytes */;
    float distance_reference /* 4 bytes */;
    float attenuation /* 4 bytes */;
    float cone_angle_outer /* 4 bytes */;
    float cone_angle_inner /* 4 bytes */;
    float cone_volume_outer /* 4 bytes */;
    float volume /* 4 bytes */;
    float pitch /* 4 bytes */;
    short flag /* 2 bytes */;
    short pad1[3] /* 6 bytes */;
};

struct MovieClipProxy {
    char dir[768] /* 768 bytes */;
    short tc /* 2 bytes */;
    short quality /* 2 bytes */;
    short build_size_flag /* 2 bytes */;
    short build_tc_flag /* 2 bytes */;
};

struct MovieReconstructedCamera {
    int framenr /* 4 bytes */;
    float error /* 4 bytes */;
    float mat[4][4] /* 64 bytes */;
};

struct MovieTrackingCamera {
    void *intrinsics /* 8 bytes */;
    short distortion_model /* 2 bytes */;
    short pad /* 2 bytes */;
    float sensor_width /* 4 bytes */;
    float pixel_aspect /* 4 bytes */;
    float focal /* 4 bytes */;
    short units /* 2 bytes */;
    short pad1 /* 2 bytes */;
    float principal[2] /* 8 bytes */;
    float k1 /* 4 bytes */;
    float k2 /* 4 bytes */;
    float k3 /* 4 bytes */;
    float division_k1 /* 4 bytes */;
    float division_k2 /* 4 bytes */;
};

struct MovieTrackingTrack {
    MovieTrackingTrack *next /* 8 bytes */;
    MovieTrackingTrack *prev /* 8 bytes */;
    char name[64] /* 64 bytes */;
    float pat_min[2] /* 8 bytes */;
    float pat_max[2] /* 8 bytes */;
    float search_min[2] /* 8 bytes */;
    float search_max[2] /* 8 bytes */;
    float offset[2] /* 8 bytes */;
    int markersnr /* 4 bytes */;
    int last_marker /* 4 bytes */;
    MovieTrackingMarker *markers /* 8 bytes */;
    float bundle_pos[3] /* 12 bytes */;
    float error /* 4 bytes */;
    int flag /* 4 bytes */;
    int pat_flag /* 4 bytes */;
    int search_flag /* 4 bytes */;
    float color[3] /* 12 bytes */;
    short frames_limit /* 2 bytes */;
    short margin /* 2 bytes */;
    short pattern_match /* 2 bytes */;
    short motion_model /* 2 bytes */;
    int algorithm_flag /* 4 bytes */;
    float minimum_correlation /* 4 bytes */;
    bGPdata *gpd /* 8 bytes */;
    float weight /* 4 bytes */;
    float pad /* 4 bytes */;
};

struct MovieTrackingPlaneMarker {
    float corners[4][2] /* 32 bytes */;
    int framenr /* 4 bytes */;
    int flag /* 4 bytes */;
};

struct MovieTrackingPlaneTrack {
    MovieTrackingPlaneTrack *next /* 8 bytes */;
    MovieTrackingPlaneTrack *prev /* 8 bytes */;
    char name[64] /* 64 bytes */;
    MovieTrackingTrack **point_tracks /* 8 bytes */;
    int point_tracksnr /* 4 bytes */;
    int pad /* 4 bytes */;
    MovieTrackingPlaneMarker *markers /* 8 bytes */;
    int markersnr /* 4 bytes */;
    int flag /* 4 bytes */;
    Image *image /* 8 bytes */;
    float image_opacity /* 4 bytes */;
    int last_marker /* 4 bytes */;
};

struct MovieTrackingSettings {
    int flag /* 4 bytes */;
    short default_motion_model /* 2 bytes */;
    short default_algorithm_flag /* 2 bytes */;
    float default_minimum_correlation /* 4 bytes */;
    short default_pattern_size /* 2 bytes */;
    short default_search_size /* 2 bytes */;
    short default_frames_limit /* 2 bytes */;
    short default_margin /* 2 bytes */;
    short default_pattern_match /* 2 bytes */;
    short default_flag /* 2 bytes */;
    float default_weight /* 4 bytes */;
    short motion_flag /* 2 bytes */;
    short speed /* 2 bytes */;
    int keyframe1 /* 4 bytes */;
    int keyframe2 /* 4 bytes */;
    int reconstruction_flag /* 4 bytes */;
    short refine_camera_intrinsics /* 2 bytes */;
    short pad2 /* 2 bytes */;
    float dist /* 4 bytes */;
    int clean_frames /* 4 bytes */;
    int clean_action /* 4 bytes */;
    float clean_error /* 4 bytes */;
    float object_distance /* 4 bytes */;
    int pad3 /* 4 bytes */;
};

struct MovieTrackingStabilization {
    int flag /* 4 bytes */;
    int tot_track /* 4 bytes */;
    int act_track /* 4 bytes */;
    float maxscale /* 4 bytes */;
    MovieTrackingTrack *rot_track /* 8 bytes */;
    float locinf /* 4 bytes */;
    float scaleinf /* 4 bytes */;
    float rotinf /* 4 bytes */;
    int filter /* 4 bytes */;
    int ok /* 4 bytes */;
    float scale /* 4 bytes */;
};

struct MovieTrackingReconstruction {
    int flag /* 4 bytes */;
    float error /* 4 bytes */;
    int last_camera /* 4 bytes */;
    int camnr /* 4 bytes */;
    MovieReconstructedCamera *cameras /* 8 bytes */;
};

struct MovieTrackingObject {
    MovieTrackingObject *next /* 8 bytes */;
    MovieTrackingObject *prev /* 8 bytes */;
    char name[64] /* 64 bytes */;
    int flag /* 4 bytes */;
    float scale /* 4 bytes */;
    ListBase tracks /* 16 bytes */;
    ListBase plane_tracks /* 16 bytes */;
    MovieTrackingReconstruction reconstruction /* 24 bytes */;
    int keyframe1 /* 4 bytes */;
    int keyframe2 /* 4 bytes */;
};

struct MovieTrackingStats {
    char message[256] /* 256 bytes */;
};

struct MovieTrackingDopesheetChannel {
    MovieTrackingDopesheetChannel *next /* 8 bytes */;
    MovieTrackingDopesheetChannel *prev /* 8 bytes */;
    MovieTrackingTrack *track /* 8 bytes */;
    int pad /* 4 bytes */;
    char name[64] /* 64 bytes */;
    int tot_segment /* 4 bytes */;
    int *segments /* 8 bytes */;
    int max_segment /* 4 bytes */;
    int total_frames /* 4 bytes */;
};

struct MovieTrackingDopesheetCoverageSegment {
    MovieTrackingDopesheetCoverageSegment *next /* 8 bytes */;
    MovieTrackingDopesheetCoverageSegment *prev /* 8 bytes */;
    int coverage /* 4 bytes */;
    int start_frame /* 4 bytes */;
    int end_frame /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct MovieTrackingDopesheet {
    int ok /* 4 bytes */;
    short sort_method /* 2 bytes */;
    short flag /* 2 bytes */;
    ListBase coverage_segments /* 16 bytes */;
    ListBase channels /* 16 bytes */;
    int tot_channel /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct MovieTracking {
    MovieTrackingSettings settings /* 72 bytes */;
    MovieTrackingCamera camera /* 56 bytes */;
    ListBase tracks /* 16 bytes */;
    ListBase plane_tracks /* 16 bytes */;
    MovieTrackingReconstruction reconstruction /* 24 bytes */;
    MovieTrackingStabilization stabilization /* 48 bytes */;
    MovieTrackingTrack *act_track /* 8 bytes */;
    MovieTrackingPlaneTrack *act_plane_track /* 8 bytes */;
    ListBase objects /* 16 bytes */;
    int objectnr /* 4 bytes */;
    int tot_object /* 4 bytes */;
    MovieTrackingStats *stats /* 8 bytes */;
    MovieTrackingDopesheet dopesheet /* 48 bytes */;
};

struct MovieClip {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
    char name[1024] /* 1024 bytes */;
    int source /* 4 bytes */;
    int lastframe /* 4 bytes */;
    int lastsize[2] /* 8 bytes */;
    float aspx /* 4 bytes */;
    float aspy /* 4 bytes */;
    void *anim /* 8 bytes */;
    void *cache /* 8 bytes */;
    bGPdata *gpd /* 8 bytes */;
    MovieTracking tracking /* 328 bytes */;
    void *tracking_context /* 8 bytes */;
    MovieClipProxy proxy /* 776 bytes */;
    int flag /* 4 bytes */;
    int len /* 4 bytes */;
    int start_frame /* 4 bytes */;
    int frame_offset /* 4 bytes */;
    ColorManagedColorspaceSettings colorspace_settings /* 64 bytes */;
};

struct DynamicPaintSurface {
    DynamicPaintSurface *next /* 8 bytes */;
    DynamicPaintSurface *prev /* 8 bytes */;
    DynamicPaintCanvasSettings *canvas /* 8 bytes */;
    void *data /* 8 bytes */;
    Group *brush_group /* 8 bytes */;
    EffectorWeights *effector_weights /* 8 bytes */;
    PointCache *pointcache /* 8 bytes */;
    ListBase ptcaches /* 16 bytes */;
    int current_frame /* 4 bytes */;
    char name[64] /* 64 bytes */;
    short format /* 2 bytes */;
    short type /* 2 bytes */;
    short disp_type /* 2 bytes */;
    short image_fileformat /* 2 bytes */;
    short effect_ui /* 2 bytes */;
    short preview_id /* 2 bytes */;
    short init_color_type /* 2 bytes */;
    short pad_s /* 2 bytes */;
    int flags /* 4 bytes */;
    int effect /* 4 bytes */;
    int image_resolution /* 4 bytes */;
    int substeps /* 4 bytes */;
    int start_frame /* 4 bytes */;
    int end_frame /* 4 bytes */;
    int pad /* 4 bytes */;
    float init_color[4] /* 16 bytes */;
    Tex *init_texture /* 8 bytes */;
    char init_layername[64] /* 64 bytes */;
    int dry_speed /* 4 bytes */;
    int diss_speed /* 4 bytes */;
    float color_dry_threshold /* 4 bytes */;
    float depth_clamp /* 4 bytes */;
    float disp_factor /* 4 bytes */;
    float spread_speed /* 4 bytes */;
    float color_spread_speed /* 4 bytes */;
    float shrink_speed /* 4 bytes */;
    float drip_vel /* 4 bytes */;
    float drip_acc /* 4 bytes */;
    float influence_scale /* 4 bytes */;
    float radius_scale /* 4 bytes */;
    float wave_damping /* 4 bytes */;
    float wave_speed /* 4 bytes */;
    float wave_timescale /* 4 bytes */;
    float wave_spring /* 4 bytes */;
    float wave_smoothness /* 4 bytes */;
    int pad2 /* 4 bytes */;
    char uvlayer_name[64] /* 64 bytes */;
    char image_output_path[1024] /* 1024 bytes */;
    char output_name[64] /* 64 bytes */;
    char output_name2[64] /* 64 bytes */;
};

struct DynamicPaintCanvasSettings {
    DynamicPaintModifierData *pmd /* 8 bytes */;
    void *dm /* 8 bytes */;
    ListBase surfaces /* 16 bytes */;
    short active_sur /* 2 bytes */;
    short flags /* 2 bytes */;
    int pad /* 4 bytes */;
    char error[64] /* 64 bytes */;
};

struct DynamicPaintBrushSettings {
    DynamicPaintModifierData *pmd /* 8 bytes */;
    void *dm /* 8 bytes */;
    ParticleSystem *psys /* 8 bytes */;
    Material *mat /* 8 bytes */;
    int flags /* 4 bytes */;
    int collision /* 4 bytes */;
    float r /* 4 bytes */;
    float g /* 4 bytes */;
    float b /* 4 bytes */;
    float alpha /* 4 bytes */;
    float wetness /* 4 bytes */;
    float particle_radius /* 4 bytes */;
    float particle_smooth /* 4 bytes */;
    float paint_distance /* 4 bytes */;
    ColorBand *paint_ramp /* 8 bytes */;
    ColorBand *vel_ramp /* 8 bytes */;
    short proximity_falloff /* 2 bytes */;
    short wave_type /* 2 bytes */;
    short ray_dir /* 2 bytes */;
    short pad /* 2 bytes */;
    float wave_factor /* 4 bytes */;
    float wave_clamp /* 4 bytes */;
    float max_velocity /* 4 bytes */;
    float smudge_strength /* 4 bytes */;
};

struct Mask {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
    ListBase masklayers /* 16 bytes */;
    int masklay_act /* 4 bytes */;
    int masklay_tot /* 4 bytes */;
    int sfra /* 4 bytes */;
    int efra /* 4 bytes */;
    int flag /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct MaskParent {
    int id_type /* 4 bytes */;
    int type /* 4 bytes */;
    ID *id /* 8 bytes */;
    char parent[64] /* 64 bytes */;
    char sub_parent[64] /* 64 bytes */;
    float parent_orig[2] /* 8 bytes */;
    float parent_corners_orig[4][2] /* 32 bytes */;
};

struct MaskSplinePointUW {
    float u /* 4 bytes */;
    float w /* 4 bytes */;
    int flag /* 4 bytes */;
};

struct MaskSplinePoint {
    BezTriple bezt /* 72 bytes */;
    int pad /* 4 bytes */;
    int tot_uw /* 4 bytes */;
    MaskSplinePointUW *uw /* 8 bytes */;
    MaskParent parent /* 184 bytes */;
};

struct MaskSpline {
    MaskSpline *next /* 8 bytes */;
    MaskSpline *prev /* 8 bytes */;
    short flag /* 2 bytes */;
    char offset_mode /* 1 bytes */;
    char weight_interp /* 1 bytes */;
    int tot_point /* 4 bytes */;
    MaskSplinePoint *points /* 8 bytes */;
    MaskParent parent /* 184 bytes */;
    MaskSplinePoint *points_deform /* 8 bytes */;
};

struct MaskLayerShape {
    MaskLayerShape *next /* 8 bytes */;
    MaskLayerShape *prev /* 8 bytes */;
    float *data /* 8 bytes */;
    int tot_vert /* 4 bytes */;
    int frame /* 4 bytes */;
    char flag /* 1 bytes */;
    char pad[7] /* 7 bytes */;
};

struct MaskLayer {
    MaskLayer *next /* 8 bytes */;
    MaskLayer *prev /* 8 bytes */;
    char name[64] /* 64 bytes */;
    ListBase splines /* 16 bytes */;
    ListBase splines_shapes /* 16 bytes */;
    MaskSpline *act_spline /* 8 bytes */;
    MaskSplinePoint *act_point /* 8 bytes */;
    float alpha /* 4 bytes */;
    char blend /* 1 bytes */;
    char blend_flag /* 1 bytes */;
    char falloff /* 1 bytes */;
    char pad[7] /* 7 bytes */;
    char flag /* 1 bytes */;
    char restrictflag /* 1 bytes */;
};

struct RigidBodyWorld {
    EffectorWeights *effector_weights /* 8 bytes */;
    Group *group /* 8 bytes */;
    Object **objects /* 8 bytes */;
    Group *constraints /* 8 bytes */;
    int pad /* 4 bytes */;
    float ltime /* 4 bytes */;
    PointCache *pointcache /* 8 bytes */;
    ListBase ptcaches /* 16 bytes */;
    int numbodies /* 4 bytes */;
    short steps_per_second /* 2 bytes */;
    short num_solver_iterations /* 2 bytes */;
    int flag /* 4 bytes */;
    float time_scale /* 4 bytes */;
    void *physics_world /* 8 bytes */;
};

struct RigidBodyOb {
    void *physics_object /* 8 bytes */;
    void *physics_shape /* 8 bytes */;
    short type /* 2 bytes */;
    short shape /* 2 bytes */;
    int flag /* 4 bytes */;
    int col_groups /* 4 bytes */;
    short mesh_source /* 2 bytes */;
    short pad /* 2 bytes */;
    float mass /* 4 bytes */;
    float friction /* 4 bytes */;
    float restitution /* 4 bytes */;
    float margin /* 4 bytes */;
    float lin_damping /* 4 bytes */;
    float ang_damping /* 4 bytes */;
    float lin_sleep_thresh /* 4 bytes */;
    float ang_sleep_thresh /* 4 bytes */;
    float orn[4] /* 16 bytes */;
    float pos[3] /* 12 bytes */;
    float pad1 /* 4 bytes */;
};

struct RigidBodyCon {
    Object *ob1 /* 8 bytes */;
    Object *ob2 /* 8 bytes */;
    short type /* 2 bytes */;
    short num_solver_iterations /* 2 bytes */;
    int flag /* 4 bytes */;
    float breaking_threshold /* 4 bytes */;
    float pad /* 4 bytes */;
    float limit_lin_x_lower /* 4 bytes */;
    float limit_lin_x_upper /* 4 bytes */;
    float limit_lin_y_lower /* 4 bytes */;
    float limit_lin_y_upper /* 4 bytes */;
    float limit_lin_z_lower /* 4 bytes */;
    float limit_lin_z_upper /* 4 bytes */;
    float limit_ang_x_lower /* 4 bytes */;
    float limit_ang_x_upper /* 4 bytes */;
    float limit_ang_y_lower /* 4 bytes */;
    float limit_ang_y_upper /* 4 bytes */;
    float limit_ang_z_lower /* 4 bytes */;
    float limit_ang_z_upper /* 4 bytes */;
    float spring_stiffness_x /* 4 bytes */;
    float spring_stiffness_y /* 4 bytes */;
    float spring_stiffness_z /* 4 bytes */;
    float spring_damping_x /* 4 bytes */;
    float spring_damping_y /* 4 bytes */;
    float spring_damping_z /* 4 bytes */;
    float motor_lin_target_velocity /* 4 bytes */;
    float motor_ang_target_velocity /* 4 bytes */;
    float motor_lin_max_impulse /* 4 bytes */;
    float motor_ang_max_impulse /* 4 bytes */;
    void *physics_constraint /* 8 bytes */;
};

struct FreestyleLineSet {
    FreestyleLineSet *next /* 8 bytes */;
    FreestyleLineSet *prev /* 8 bytes */;
    char name[64] /* 64 bytes */;
    int flags /* 4 bytes */;
    int selection /* 4 bytes */;
    short qi /* 2 bytes */;
    short pad1 /* 2 bytes */;
    int qi_start /* 4 bytes */;
    int qi_end /* 4 bytes */;
    int edge_types /* 4 bytes */;
    int exclude_edge_types /* 4 bytes */;
    int pad2 /* 4 bytes */;
    Group *group /* 8 bytes */;
    FreestyleLineStyle *linestyle /* 8 bytes */;
};

struct FreestyleModuleConfig {
    FreestyleModuleConfig *next /* 8 bytes */;
    FreestyleModuleConfig *prev /* 8 bytes */;
    Text *script /* 8 bytes */;
    short is_displayed /* 2 bytes */;
    short pad[3] /* 6 bytes */;
};

struct LineStyleModifier {
    LineStyleModifier *next /* 8 bytes */;
    LineStyleModifier *prev /* 8 bytes */;
    char name[64] /* 64 bytes */;
    int type /* 4 bytes */;
    float influence /* 4 bytes */;
    int flags /* 4 bytes */;
    int blend /* 4 bytes */;
};

struct LineStyleColorModifier_AlongStroke {
    LineStyleModifier modifier /* 96 bytes */;
    ColorBand *color_ramp /* 8 bytes */;
};

struct LineStyleAlphaModifier_AlongStroke {
    LineStyleModifier modifier /* 96 bytes */;
    CurveMapping *curve /* 8 bytes */;
    int flags /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct LineStyleThicknessModifier_AlongStroke {
    LineStyleModifier modifier /* 96 bytes */;
    CurveMapping *curve /* 8 bytes */;
    int flags /* 4 bytes */;
    float value_min /* 4 bytes */;
    float value_max /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct LineStyleColorModifier_DistanceFromCamera {
    LineStyleModifier modifier /* 96 bytes */;
    ColorBand *color_ramp /* 8 bytes */;
    float range_min /* 4 bytes */;
    float range_max /* 4 bytes */;
};

struct LineStyleAlphaModifier_DistanceFromCamera {
    LineStyleModifier modifier /* 96 bytes */;
    CurveMapping *curve /* 8 bytes */;
    int flags /* 4 bytes */;
    float range_min /* 4 bytes */;
    float range_max /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct LineStyleThicknessModifier_DistanceFromCamera {
    LineStyleModifier modifier /* 96 bytes */;
    CurveMapping *curve /* 8 bytes */;
    int flags /* 4 bytes */;
    float range_min /* 4 bytes */;
    float range_max /* 4 bytes */;
    float value_min /* 4 bytes */;
    float value_max /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct LineStyleColorModifier_DistanceFromObject {
    LineStyleModifier modifier /* 96 bytes */;
    Object *target /* 8 bytes */;
    ColorBand *color_ramp /* 8 bytes */;
    float range_min /* 4 bytes */;
    float range_max /* 4 bytes */;
};

struct LineStyleAlphaModifier_DistanceFromObject {
    LineStyleModifier modifier /* 96 bytes */;
    Object *target /* 8 bytes */;
    CurveMapping *curve /* 8 bytes */;
    int flags /* 4 bytes */;
    float range_min /* 4 bytes */;
    float range_max /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct LineStyleThicknessModifier_DistanceFromObject {
    LineStyleModifier modifier /* 96 bytes */;
    Object *target /* 8 bytes */;
    CurveMapping *curve /* 8 bytes */;
    int flags /* 4 bytes */;
    float range_min /* 4 bytes */;
    float range_max /* 4 bytes */;
    float value_min /* 4 bytes */;
    float value_max /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct LineStyleColorModifier_Material {
    LineStyleModifier modifier /* 96 bytes */;
    ColorBand *color_ramp /* 8 bytes */;
    int flags /* 4 bytes */;
    int mat_attr /* 4 bytes */;
};

struct LineStyleAlphaModifier_Material {
    LineStyleModifier modifier /* 96 bytes */;
    CurveMapping *curve /* 8 bytes */;
    int flags /* 4 bytes */;
    int mat_attr /* 4 bytes */;
};

struct LineStyleThicknessModifier_Material {
    LineStyleModifier modifier /* 96 bytes */;
    CurveMapping *curve /* 8 bytes */;
    int flags /* 4 bytes */;
    float value_min /* 4 bytes */;
    float value_max /* 4 bytes */;
    int mat_attr /* 4 bytes */;
};

struct LineStyleGeometryModifier_Sampling {
    LineStyleModifier modifier /* 96 bytes */;
    float sampling /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct LineStyleGeometryModifier_BezierCurve {
    LineStyleModifier modifier /* 96 bytes */;
    float error /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct LineStyleGeometryModifier_SinusDisplacement {
    LineStyleModifier modifier /* 96 bytes */;
    float wavelength /* 4 bytes */;
    float amplitude /* 4 bytes */;
    float phase /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct LineStyleGeometryModifier_SpatialNoise {
    LineStyleModifier modifier /* 96 bytes */;
    float amplitude /* 4 bytes */;
    float scale /* 4 bytes */;
    int octaves /* 4 bytes */;
    int flags /* 4 bytes */;
};

struct LineStyleGeometryModifier_PerlinNoise1D {
    LineStyleModifier modifier /* 96 bytes */;
    float frequency /* 4 bytes */;
    float amplitude /* 4 bytes */;
    float angle /* 4 bytes */;
    int octaves /* 4 bytes */;
    int seed /* 4 bytes */;
    int pad1 /* 4 bytes */;
};

struct LineStyleGeometryModifier_PerlinNoise2D {
    LineStyleModifier modifier /* 96 bytes */;
    float frequency /* 4 bytes */;
    float amplitude /* 4 bytes */;
    float angle /* 4 bytes */;
    int octaves /* 4 bytes */;
    int seed /* 4 bytes */;
    int pad1 /* 4 bytes */;
};

struct LineStyleGeometryModifier_BackboneStretcher {
    LineStyleModifier modifier /* 96 bytes */;
    float backbone_length /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct LineStyleGeometryModifier_TipRemover {
    LineStyleModifier modifier /* 96 bytes */;
    float tip_length /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct LineStyleGeometryModifier_Polygonalization {
    LineStyleModifier modifier /* 96 bytes */;
    float error /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct LineStyleGeometryModifier_GuidingLines {
    LineStyleModifier modifier /* 96 bytes */;
    float offset /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct LineStyleGeometryModifier_Blueprint {
    LineStyleModifier modifier /* 96 bytes */;
    int flags /* 4 bytes */;
    int rounds /* 4 bytes */;
    float backbone_length /* 4 bytes */;
    int random_radius /* 4 bytes */;
    int random_center /* 4 bytes */;
    int random_backbone /* 4 bytes */;
};

struct LineStyleGeometryModifier_2DOffset {
    LineStyleModifier modifier /* 96 bytes */;
    float start /* 4 bytes */;
    float end /* 4 bytes */;
    float x /* 4 bytes */;
    float y /* 4 bytes */;
};

struct LineStyleGeometryModifier_2DTransform {
    LineStyleModifier modifier /* 96 bytes */;
    int pivot /* 4 bytes */;
    float scale_x /* 4 bytes */;
    float scale_y /* 4 bytes */;
    float angle /* 4 bytes */;
    float pivot_u /* 4 bytes */;
    float pivot_x /* 4 bytes */;
    float pivot_y /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct LineStyleThicknessModifier_Calligraphy {
    LineStyleModifier modifier /* 96 bytes */;
    float min_thickness /* 4 bytes */;
    float max_thickness /* 4 bytes */;
    float orientation /* 4 bytes */;
    int pad /* 4 bytes */;
};

struct FreestyleLineStyle {
    ID id /* 120 bytes */;
    AnimData *adt /* 8 bytes */;
    float r /* 4 bytes */;
    float g /* 4 bytes */;
    float b /* 4 bytes */;
    float alpha /* 4 bytes */;
    float thickness /* 4 bytes */;
    int thickness_position /* 4 bytes */;
    float thickness_ratio /* 4 bytes */;
    int flag /* 4 bytes */;
    int caps /* 4 bytes */;
    int chaining /* 4 bytes */;
    int rounds /* 4 bytes */;
    float split_length /* 4 bytes */;
    float min_angle /* 4 bytes */;
    float max_angle /* 4 bytes */;
    float min_length /* 4 bytes */;
    float max_length /* 4 bytes */;
    int chain_count /* 4 bytes */;
    short split_dash1 /* 2 bytes */;
    short split_gap1 /* 2 bytes */;
    short split_dash2 /* 2 bytes */;
    short split_gap2 /* 2 bytes */;
    short split_dash3 /* 2 bytes */;
    short split_gap3 /* 2 bytes */;
    int sort_key /* 4 bytes */;
    int integration_type /* 4 bytes */;
    float texstep /* 4 bytes */;
    short texact /* 2 bytes */;
    short pr_texture /* 2 bytes */;
    short use_nodes /* 2 bytes */;
    short pad[3] /* 6 bytes */;
    short dash1 /* 2 bytes */;
    short gap1 /* 2 bytes */;
    short dash2 /* 2 bytes */;
    short gap2 /* 2 bytes */;
    short dash3 /* 2 bytes */;
    short gap3 /* 2 bytes */;
    int panel /* 4 bytes */;
    MTex *mtex[18] /* 144 bytes */;
    bNodeTree *nodetree /* 8 bytes */;
    ListBase color_modifiers /* 16 bytes */;
    ListBase alpha_modifiers /* 16 bytes */;
    ListBase thickness_modifiers /* 16 bytes */;
    ListBase geometry_modifiers /* 16 bytes */;
};

}



#endif//_Blender_h_
