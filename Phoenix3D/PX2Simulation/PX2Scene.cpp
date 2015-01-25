// PX2Scene.cpp

#include "PX2Scene.hpp"
#include "PX2Project.hpp"
#include "PX2Creater.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Node, Scene);
PX2_IMPLEMENT_STREAM(Scene);
PX2_IMPLEMENT_FACTORY(Scene);
PX2_IMPLEMENT_DEFAULT_NAMES(Node, Scene);

//----------------------------------------------------------------------------
Scene::Scene()
{
	SetName("Scene");

	CameraActor *camActor = new0 CameraActor();
	AttachChild(camActor);
	camActor->LocalTransform.SetTranslate(APoint(0.0f, -1.0f, 1.0f));

	SetUseCameraActor(camActor);

	PX2_CREATER.CreateActor_Box(this, APoint::ORIGIN);
}
//----------------------------------------------------------------------------
Scene::~Scene()
{
}
//----------------------------------------------------------------------------
void Scene::SetUseCameraActor(CameraActor *cameraActor)
{
	mCameraActor = cameraActor;

	Project *proj = Project::GetSingletonPtr();
	if (proj && mCameraActor)
	{
		RenderStep *renderStep = proj->GetSceneRenderStep();
		if (renderStep)
		{
			renderStep->SetCamera(mCameraActor->GetCamera());
		}
	}
}
//----------------------------------------------------------------------------
int Scene::AttachChild(Movable* child)
{
	return Node::AttachChild(child);
}
//----------------------------------------------------------------------------
void Scene::UpdateWorldData(double applicationTime)
{
	Node::UpdateWorldData(applicationTime);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// �־û�֧��
//----------------------------------------------------------------------------
Scene::Scene(LoadConstructor value)
	:
	Node(value)
{
}
//----------------------------------------------------------------------------
void Scene::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Node::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(Scene, source);
}
//----------------------------------------------------------------------------
void Scene::Link(InStream& source)
{
	Node::Link(source);
}
//----------------------------------------------------------------------------
void Scene::PostLink()
{
	Node::PostLink();
}
//----------------------------------------------------------------------------
bool Scene::Register(OutStream& target) const
{
	return Node::Register(target);
}
//----------------------------------------------------------------------------
void Scene::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Node::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(Scene, target);
}
//----------------------------------------------------------------------------
int Scene::GetStreamingSize(Stream &stream) const
{
	int size = Node::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------