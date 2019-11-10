typedef unsigned char   undefined;

typedef unsigned long long    GUID;
typedef unsigned int    ImageBaseOffset32;
typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
float10
typedef long long    longlong;
typedef char    sbyte;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef short    wchar_t;
typedef unsigned short    word;
typedef struct SweepRenderer SweepRenderer, *PSweepRenderer;

typedef struct ProjectingParticleCache ProjectingParticleCache, *PProjectingParticleCache;

typedef struct IndexTriVertexBuffer IndexTriVertexBuffer, *PIndexTriVertexBuffer;

typedef struct Point3D Point3D, *PPoint3D;

typedef struct Slice_t Slice_t, *PSlice_t;

typedef struct SmartArray<SmartArray<YZ,0,0>,0,16> SmartArray<SmartArray<YZ,0,0>,0,16>, *PSmartArray<SmartArray<YZ,0,0>,0,16>;

typedef struct PCacheElem_t PCacheElem_t, *PPCacheElem_t;

typedef struct SmartArray<pcache_YZ_t,0,16> SmartArray<pcache_YZ_t,0,16>, *PSmartArray<pcache_YZ_t,0,16>;

typedef struct IMesh IMesh, *PIMesh;

typedef struct CMeshBuilder CMeshBuilder, *PCMeshBuilder;

typedef union Point3D_u_0 Point3D_u_0, *PPoint3D_u_0;

typedef union CubeInfo CubeInfo, *PCubeInfo;

typedef struct SmartArray<YZ,0,0> SmartArray<YZ,0,0>, *PSmartArray<YZ,0,0>;

typedef struct SmartArray<YZ,0,16> SmartArray<YZ,0,16>, *PSmartArray<YZ,0,16>;

typedef struct ImpParticle ImpParticle, *PImpParticle;

typedef struct pcache_YZ_t pcache_YZ_t, *Ppcache_YZ_t;

typedef enum MaterialPrimitiveType_t {
    MATERIAL_HETEROGENOUS=11,
    MATERIAL_INSTANCED_QUADS=10,
    MATERIAL_LINES=1,
    MATERIAL_LINE_LOOP=5,
    MATERIAL_LINE_STRIP=4,
    MATERIAL_POINTS=0,
    MATERIAL_POLYGON=6,
    MATERIAL_QUADS=7,
    MATERIAL_SUBD_QUADS_EXTRA=8,
    MATERIAL_SUBD_QUADS_REG=9,
    MATERIAL_TRIANGLES=2,
    MATERIAL_TRIANGLE_STRIP=3
} MaterialPrimitiveType_t;

typedef struct CIndexBuilder CIndexBuilder, *PCIndexBuilder;

typedef struct CVertexBuilder CVertexBuilder, *PCVertexBuilder;

typedef union __m128 __m128, *P__m128;

typedef struct CubeInfo_s_0 CubeInfo_s_0, *PCubeInfo_s_0;

typedef struct YZ YZ, *PYZ;

typedef struct IIndexBuffer IIndexBuffer, *PIIndexBuffer;

typedef struct IVertexBuffer IVertexBuffer, *PIVertexBuffer;

typedef ulonglong __uint64;

union __m128 {
    float m128_f32[4];
    __uint64 m128_u64[2];
    char m128_i8[16];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    uchar m128_u8[16];
    ushort m128_u16[8];
    uint m128_u32[4];
};

union Point3D_u_0 {
    union __m128 sse_vec;
    float p[4];
};

struct Point3D {
    union Point3D_u_0 field_0x0;
};

struct SmartArray<SmartArray<YZ,0,0>,0,16> {
    struct SmartArray<YZ,0,0> * a;
    int size;
    int capacity;
};

struct SmartArray<YZ,0,16> {
    struct YZ * a;
    int size;
    int capacity;
};

struct SmartArray<YZ,0,0> {
    struct YZ * a;
    int size;
    int capacity;
};

struct Slice_t {
    union CubeInfo[101] * corners;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    undefined field_0x8;
    undefined field_0x9;
    undefined field_0xa;
    undefined field_0xb;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    struct SmartArray<YZ,0,0> todo_list;
    struct SmartArray<YZ,0,16> seed_list;
};

struct SweepRenderer {
    struct ProjectingParticleCache * pCache;
    struct IndexTriVertexBuffer * vertexBuffer;
    int maxNoSlicesToDraw;
    int last_slice_drawn;
    bool polygonizationEnabled;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    undefined field_0x18;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    struct Point3D offset;
    struct Point3D outerBBMins;
    struct Point3D outerBBMaxs;
    struct Point3D innerBBMins;
    struct Point3D innerBBMaxs;
    undefined field_0x70;
    undefined field_0x71;
    undefined field_0x72;
    undefined field_0x73;
    undefined field_0x74;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;
    undefined field_0x78;
    undefined field_0x79;
    undefined field_0x7a;
    undefined field_0x7b;
    struct Slice_t slices[102];
    undefined field_0x106c;
    undefined field_0x106d;
    undefined field_0x106e;
    undefined field_0x106f;
    undefined field_0x1070;
    undefined field_0x1071;
    undefined field_0x1072;
    undefined field_0x1073;
    undefined field_0x1074;
    undefined field_0x1075;
    undefined field_0x1076;
    undefined field_0x1077;
    undefined field_0x1078;
    undefined field_0x1079;
    undefined field_0x107a;
    undefined field_0x107b;
    undefined field_0x107c;
    undefined field_0x107d;
    undefined field_0x107e;
    undefined field_0x107f;
    undefined field_0x1080;
    undefined field_0x1081;
    undefined field_0x1082;
    undefined field_0x1083;
    struct SmartArray<SmartArray<YZ,0,0>,0,16> unused_todo_lists;
    int n_alloced_slice_corners;
    int n_alloced_slice_corner_infos;
    int n_alloced_slice_todo_lists;
};

struct YZ {
    uchar y;
    uchar z;
};

struct IndexTriVertexBuffer {
    ushort m_curTime;
    ushort m_nVerticesOutput;
    struct IMesh * m_pMesh;
    struct CMeshBuilder * m_pMeshBuilder;
    ushort m_stat_no_flushes;
};

struct IIndexBuffer {
};

struct SmartArray<pcache_YZ_t,0,16> {
    struct pcache_YZ_t * a;
    int size;
    int capacity;
};

struct ProjectingParticleCache {
    struct PCacheElem_t * botSentinel;
    struct PCacheElem_t * midSentinel;
    struct PCacheElem_t * topSentinel;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    undefined field_0x18;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    undefined field_0x20;
    undefined field_0x21;
    undefined field_0x22;
    undefined field_0x23;
    struct SmartArray<pcache_YZ_t,0,16> clearList;
    int curCacheElement;
    struct PCacheElem_t *[101] * cachePlane;
};

struct PCacheElem_t {
    short center_x;
    uchar bot_x;
    uchar top_x;
    struct PCacheElem_t * prev;
    struct PCacheElem_t * next;
    struct ImpParticle * p;
};

struct ImpParticle {
    struct Point3D center;
    float fieldRScaleSq;
    float scale;
};

struct CubeInfo_s_0 {
    ushort cornerInfoNo;
    bool doneAbove;
    bool doneBelow;
};

struct IVertexBuffer {
};

union CubeInfo {
    struct CubeInfo_s_0 _s_0;
    uint everything;
};

struct CVertexBuilder {
    undefined field_0x0;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    undefined field_0x8;
    undefined field_0x9;
    undefined field_0xa;
    undefined field_0xb;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    undefined field_0x18;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    undefined field_0x20;
    undefined field_0x21;
    undefined field_0x22;
    undefined field_0x23;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    undefined field_0x30;
    undefined field_0x31;
    undefined field_0x32;
    undefined field_0x33;
    undefined field_0x34;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
    undefined field_0x38;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    undefined field_0x40;
    undefined field_0x41;
    undefined field_0x42;
    undefined field_0x43;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    undefined field_0x50;
    undefined field_0x51;
    undefined field_0x52;
    undefined field_0x53;
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    undefined field_0x58;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    undefined field_0x60;
    undefined field_0x61;
    undefined field_0x62;
    undefined field_0x63;
    undefined field_0x64;
    undefined field_0x65;
    undefined field_0x66;
    undefined field_0x67;
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    undefined field_0x70;
    undefined field_0x71;
    undefined field_0x72;
    undefined field_0x73;
    undefined field_0x74;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;
    undefined field_0x78;
    undefined field_0x79;
    undefined field_0x7a;
    undefined field_0x7b;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    undefined field_0x80;
    undefined field_0x81;
    undefined field_0x82;
    undefined field_0x83;
    undefined field_0x84;
    undefined field_0x85;
    undefined field_0x86;
    undefined field_0x87;
    undefined field_0x88;
    undefined field_0x89;
    undefined field_0x8a;
    undefined field_0x8b;
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    undefined field_0x90;
    undefined field_0x91;
    undefined field_0x92;
    undefined field_0x93;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
    undefined field_0x98;
    undefined field_0x99;
    undefined field_0x9a;
    undefined field_0x9b;
    undefined field_0x9c;
    undefined field_0x9d;
    undefined field_0x9e;
    undefined field_0x9f;
    undefined field_0xa0;
    undefined field_0xa1;
    undefined field_0xa2;
    undefined field_0xa3;
    struct IVertexBuffer * m_pVertexBuffer;
    bool m_bModify;
    undefined field_0xa9;
    undefined field_0xaa;
    undefined field_0xab;
    int m_nMaxVertexCount;
    int m_nVertexCount;
    int m_nCurrentVertex;
    float * m_pCurrPosition;
    float * m_pCurrNormal;
    uchar * m_pCurrColor;
    float * m_pCurrTexCoord[8];
    int m_nTotalVertexCount;
    uint m_nBufferOffset;
    uint m_nBufferFirstVertex;
    bool m_bWrittenNormal:1;
    bool m_bWrittenUserData:1;
};

struct CIndexBuilder {
    undefined field_0x0;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    undefined field_0x8;
    undefined field_0x9;
    undefined field_0xa;
    undefined field_0xb;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    struct IIndexBuffer * m_pIndexBuffer;
    int m_nMaxIndexCount;
    int m_nIndexCount;
    int m_nIndexOffset;
    int m_nCurrentIndex;
    int m_nTotalIndexCount;
    uint m_nBufferOffset;
    uint m_nBufferFirstIndex;
    bool m_bModify;
};

struct CMeshBuilder {
    undefined field_0x0;
    undefined field_0x1;
    undefined field_0x2;
    undefined field_0x3;
    undefined field_0x4;
    undefined field_0x5;
    undefined field_0x6;
    undefined field_0x7;
    undefined field_0x8;
    undefined field_0x9;
    undefined field_0xa;
    undefined field_0xb;
    undefined field_0xc;
    undefined field_0xd;
    undefined field_0xe;
    undefined field_0xf;
    undefined field_0x10;
    undefined field_0x11;
    undefined field_0x12;
    undefined field_0x13;
    undefined field_0x14;
    undefined field_0x15;
    undefined field_0x16;
    undefined field_0x17;
    undefined field_0x18;
    undefined field_0x19;
    undefined field_0x1a;
    undefined field_0x1b;
    undefined field_0x1c;
    undefined field_0x1d;
    undefined field_0x1e;
    undefined field_0x1f;
    undefined field_0x20;
    undefined field_0x21;
    undefined field_0x22;
    undefined field_0x23;
    undefined field_0x24;
    undefined field_0x25;
    undefined field_0x26;
    undefined field_0x27;
    undefined field_0x28;
    undefined field_0x29;
    undefined field_0x2a;
    undefined field_0x2b;
    undefined field_0x2c;
    undefined field_0x2d;
    undefined field_0x2e;
    undefined field_0x2f;
    undefined field_0x30;
    undefined field_0x31;
    undefined field_0x32;
    undefined field_0x33;
    undefined field_0x34;
    undefined field_0x35;
    undefined field_0x36;
    undefined field_0x37;
    undefined field_0x38;
    undefined field_0x39;
    undefined field_0x3a;
    undefined field_0x3b;
    undefined field_0x3c;
    undefined field_0x3d;
    undefined field_0x3e;
    undefined field_0x3f;
    undefined field_0x40;
    undefined field_0x41;
    undefined field_0x42;
    undefined field_0x43;
    undefined field_0x44;
    undefined field_0x45;
    undefined field_0x46;
    undefined field_0x47;
    undefined field_0x48;
    undefined field_0x49;
    undefined field_0x4a;
    undefined field_0x4b;
    undefined field_0x4c;
    undefined field_0x4d;
    undefined field_0x4e;
    undefined field_0x4f;
    undefined field_0x50;
    undefined field_0x51;
    undefined field_0x52;
    undefined field_0x53;
    undefined field_0x54;
    undefined field_0x55;
    undefined field_0x56;
    undefined field_0x57;
    undefined field_0x58;
    undefined field_0x59;
    undefined field_0x5a;
    undefined field_0x5b;
    undefined field_0x5c;
    undefined field_0x5d;
    undefined field_0x5e;
    undefined field_0x5f;
    undefined field_0x60;
    undefined field_0x61;
    undefined field_0x62;
    undefined field_0x63;
    undefined field_0x64;
    undefined field_0x65;
    undefined field_0x66;
    undefined field_0x67;
    undefined field_0x68;
    undefined field_0x69;
    undefined field_0x6a;
    undefined field_0x6b;
    undefined field_0x6c;
    undefined field_0x6d;
    undefined field_0x6e;
    undefined field_0x6f;
    undefined field_0x70;
    undefined field_0x71;
    undefined field_0x72;
    undefined field_0x73;
    undefined field_0x74;
    undefined field_0x75;
    undefined field_0x76;
    undefined field_0x77;
    undefined field_0x78;
    undefined field_0x79;
    undefined field_0x7a;
    undefined field_0x7b;
    undefined field_0x7c;
    undefined field_0x7d;
    undefined field_0x7e;
    undefined field_0x7f;
    undefined field_0x80;
    undefined field_0x81;
    undefined field_0x82;
    undefined field_0x83;
    undefined field_0x84;
    undefined field_0x85;
    undefined field_0x86;
    undefined field_0x87;
    undefined field_0x88;
    undefined field_0x89;
    undefined field_0x8a;
    undefined field_0x8b;
    undefined field_0x8c;
    undefined field_0x8d;
    undefined field_0x8e;
    undefined field_0x8f;
    undefined field_0x90;
    undefined field_0x91;
    undefined field_0x92;
    undefined field_0x93;
    undefined field_0x94;
    undefined field_0x95;
    undefined field_0x96;
    undefined field_0x97;
    undefined field_0x98;
    undefined field_0x99;
    undefined field_0x9a;
    undefined field_0x9b;
    undefined field_0x9c;
    undefined field_0x9d;
    undefined field_0x9e;
    undefined field_0x9f;
    undefined field_0xa0;
    undefined field_0xa1;
    undefined field_0xa2;
    undefined field_0xa3;
    undefined field_0xa4;
    undefined field_0xa5;
    undefined field_0xa6;
    undefined field_0xa7;
    undefined field_0xa8;
    undefined field_0xa9;
    undefined field_0xaa;
    undefined field_0xab;
    undefined field_0xac;
    undefined field_0xad;
    undefined field_0xae;
    undefined field_0xaf;
    undefined field_0xb0;
    undefined field_0xb1;
    undefined field_0xb2;
    undefined field_0xb3;
    struct IMesh * m_pMesh;
    enum MaterialPrimitiveType_t m_Type;
    bool m_bGenerateIndices;
    undefined field_0xbd;
    undefined field_0xbe;
    undefined field_0xbf;
    struct CIndexBuilder m_IndexBuilder;
    undefined field_0xf1;
    undefined field_0xf2;
    undefined field_0xf3;
    struct CVertexBuilder m_VertexBuilder;
};

struct pcache_YZ_t {
    uchar y;
    uchar z;
};

struct IMesh {
};

