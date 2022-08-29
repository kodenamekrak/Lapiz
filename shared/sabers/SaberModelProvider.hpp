#pragma once

#include "custom-types/shared/macros.hpp"
#include "SaberModelRegistration.hpp"
#include "Zenject/DiContainer.hpp"
#include "GlobalNamespace/SaberManager.hpp"
#include "GlobalNamespace/SaberModelContainer.hpp"
#include "GlobalNamespace/SetSaberGlowColor.hpp"
#include "GlobalNamespace/SetSaberFakeGlowColor.hpp"
#include "System/Collections/Generic/HashSet_1.hpp"

DECLARE_CLASS_CODEGEN(Lapiz::Sabers, SaberModelProvider, Il2CppObject,
    DECLARE_INSTANCE_FIELD(Zenject::DiContainer*, _container);
    DECLARE_INSTANCE_FIELD(GlobalNamespace::SaberManager*, _saberManager);
    DECLARE_INSTANCE_FIELD(GlobalNamespace::SaberModelContainer*, _localLeftContainer);
    DECLARE_INSTANCE_FIELD(GlobalNamespace::SaberModelContainer*, _localRightContainer);
    DECLARE_INSTANCE_FIELD(SaberModelRegistrationWrapper*, _activeSaberModelRegistration);
    DECLARE_INSTANCE_FIELD(SaberModelRegistrationWrapper*, _defaultSaberModelRegistration);
    DECLARE_INSTANCE_FIELD(System::Collections::Generic::HashSet_1<GlobalNamespace::SetSaberGlowColor*>*, _earlyInittingGlowColors);
    DECLARE_INSTANCE_FIELD(System::Collections::Generic::HashSet_1<GlobalNamespace::SetSaberFakeGlowColor*>*, _earlyInittingFakeGlowColors);

    public:
        static SaberModelProvider* get_instance();
        GlobalNamespace::SaberModelController* NewModel(std::optional<GlobalNamespace::SaberType> saberType = std::nullopt);
        
        bool SetSaberGlowColor_Start_Prefix(GlobalNamespace::SetSaberGlowColor* self);
        bool SetSaberFakeGlowColor_Start_Prefix(GlobalNamespace::SetSaberFakeGlowColor* self);
        bool SaberModelContainer_Start_Prefix(GlobalNamespace::SaberModelContainer* self);

        DECLARE_CTOR(ctor, Zenject::DiContainer* container, GlobalNamespace::SaberManager* saberManager, ListWrapper<SaberModelRegistrationWrapper*> saberModelRegistrations);
        DECLARE_SIMPLE_DTOR();
    private:
        static SaberModelProvider* instance;
        GlobalNamespace::SaberModelController* CreateNew(GlobalNamespace::SaberType saberType);
)