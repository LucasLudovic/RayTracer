{ lib, sfml, fetchpatch2 }:
sfml.overrideAttrs (prev: {
  version = "3.0.1";
  src = prev.src.override {
    hash = "sha256-yTNoDHcBRzk270QHjSFVpjFKm2+uVvmVLg6XlAppwYk=";
  };

  cmakeFlags = (prev.cmakeFlags or []) ++ [
    (lib.cmakeBool "BUILD_SHARED_LIBS" true)
  ];

  patches = (prev.patches or [ ]) ++ [
    # revert pr causing a build error when SFML_INSTALL_PKGCONFIG_FILES is set
    # https://github.com/SFML/SFML/issues/3504
    (fetchpatch2 {
      url = "https://patch-diff.githubusercontent.com/raw/SFML/SFML/pull/3451.patch";
      hash = "sha256-uqr/uOr78dmi0xJ9qqodsY50AlRL04UvsBHXfFZAI8Q=";
      revert = true;
    })
  ];
})
