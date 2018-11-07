//================================================================================
//
//    ブリンフォン鏡面反射シェーダー
//    Author : Araki Kai                                作成日 : 2018/07/26
//
//================================================================================



//**********************************************************************
//
// グローバル変数
//
//**********************************************************************

// 変換行列
float4x4 MATRIX_WVP;

// ランバート拡散反射照明
float4 LAMBERT_DIFFUSE_LIGHT_VECTOR = {1.0f, 0.0f, 0.0f, 1.0f};
float4 LAMBERT_DIFFUSE_LIGHT_COLOR 	= {1.0f, 1.0f, 1.0f, 1.0f};

// フォン鏡面反射
float3 CAMERA_POSITION = {0.0f, 0.0f, 0.0f};



//**********************************************************************
//
// 構造体宣言
//
//**********************************************************************

// 頂点シェーダへの入力
struct Input_VS
{
	float4 position_ : POSITION;
	float4 normal_   : NORMAL;
};


// 頂点シェーダからの出力(ピクセルシェーダの入力)
struct Output_VS
{
	float4 position_   : POSITION;
	float4 color_	   : COLOR0;
	float3 normal_	   : TEXCOORD0;
	float3 eye_vector_ : TEXCOORD1;
};



//**********************************************************************
//
// 頂点シェーダ定義
//
//**********************************************************************

//================================================================================
//
// [ メイン頂点シェーダ関数 ]
//
//================================================================================

Output_VS mainVS(Input_VS input)
{
//------------------------------------------------------------
// 初期化

	// 出力データの作成
	Output_VS output = (Output_VS)0;


//------------------------------------------------------------
// 座標変換

	// 座標をWVP行列で変換
	output.position_ = mul(input.position_, MATRIX_WVP);


//------------------------------------------------------------
// ランバート拡散照明

	// 環境光の比率を保存
	float ambient_ratio = LAMBERT_DIFFUSE_LIGHT_VECTOR.w;

	// ライトベクトルを反転
	float4 inverse_light_vector4 = -LAMBERT_DIFFUSE_LIGHT_VECTOR;

	// 色の計算(α値も環境比率が掛かってしまうため、α値は別途代入)
	output.color_ = LAMBERT_DIFFUSE_LIGHT_COLOR * max(ambient_ratio, dot(input.normal_, inverse_light_vector4));
	output.color_.w = LAMBERT_DIFFUSE_LIGHT_COLOR.w;

	
//------------------------------------------------------------
// ピクセルシェーダーに渡す値計算

	// 視線ベクトルの作成(正規化するとちゃんと変換されなくなる：位置情報が無くなるから)
	output.eye_vector_ = CAMERA_POSITION - input.position_.xyz;

	// 法線
	output.normal_ = input.normal_.xyz;

	return output;
}



//**********************************************************************
//
// ピクセルシェーダ定義
//
//**********************************************************************

//================================================================================
//
// [ メインピクセルシェーダ関数 ]
//
//================================================================================

float4 mainPS(Output_VS input) : COLOR
{
//------------------------------------------------------------
// ブリンフォン鏡面反射

	// ライトベクトルを反転
	float3 inverse_light_vector3 = -LAMBERT_DIFFUSE_LIGHT_VECTOR.xyz;
	
	// ハーフベクトルの作成(視点ベクトルはここで正規化)
	float3 half_vector = normalize(inverse_light_vector3 + normalize(input.eye_vector_));

	// 法線
	float3 normal = normalize(input.normal_);

	// 鏡面反射を入力カラーに追加
	input.color_ += pow(max(0, dot(normal, half_vector)), 100);

	return input.color_;
}



//**********************************************************************
//
// テクニック定義
//
//**********************************************************************

//================================================================================
//
// [ テクニック(レンダリング方法をまとめたもの) ]
//
//================================================================================

technique Techique01
{
	pass P0
	{
		VertexShader = compile vs_2_0 mainVS();
		PixelShader  = compile ps_2_0 mainPS();
	}
}