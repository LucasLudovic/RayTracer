{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-24.11";
    # nixpkgs ping on sfml: 2.5.1 -> 3.0.0
    nixpkgs-sfml-pin.url = "github:NixOS/nixpkgs/daf84d2d57c43c2a57d94e1d06635445b7cdcaac";
  };

  outputs = { self, nixpkgs, nixpkgs-sfml-pin }:
    let
      forAllSystems = function:
        nixpkgs.lib.genAttrs [
          "x86_64-linux"
          "aarch64-linux"
        ]
          (system: function nixpkgs.legacyPackages.${system});
    in
    {
      devShells = forAllSystems (pkgs: {
        default = pkgs.mkShell {
          packages = with pkgs; [
            gcc14
            criterion
            pkg-config
            freetype
            libconfig
          ] ++ (with self.packages.${pkgs.system}; [
            sfml-3-0-1
          ]);
        };
      });

      formatter = forAllSystems (pkgs: pkgs.nixpkgs-fmt);

      packages = forAllSystems (pkgs:
        let
          pkgs' = nixpkgs-sfml-pin.legacyPackages.${pkgs.system};
        in
        {
          sfml-3-0-1 = pkgs'.callPackage ./sfml-3.0.1.nix { };
        });
    };
}
