Entity1 = {
	Name = "Camera",
	Components = {
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0|6|0",
				Rotation = "false|1.0|0|0|0",
				Scale = "1.0|1.0|1.0"
			}
		},
		{
			Name = "CAMERA",
			Arguments = {
			}
		},
		{
			Name = "CHANGE_CAMERA_BACKGROUND",
			Arguments = {
				r = "201",
				g = "1",
				b = "1",
				a = "1"
			}
		},
		{
			Name = "ROTATE_MENU_CAMERA",
			Arguments = {
				Speed = "5"
			}
		},
		{
            Name = "BUTTON_FUNCTIONS",
            Arguments = {
			}
        }
	}
}

Entity2 = {
	Name = "OptionsText",
	Components = {
		{
			Name = "IMAGE",
			Arguments = {
                OverlayName= "textoptions",
				XPos = "50",
				YPos = "10",
				Width = "40",
				Height = "12",
				Texture = "options_white.png",
				Depth = "1"
			}
		}
	}
}

Entity3 = {
	Name = "UI_Cursor",
	Components = {
		{
			Name = "IMAGE",
			Arguments = {
				OverlayName= "image",
				XPos = "0",
				YPos = "0",
				Width = "5",
				Height = "5",
				Texture = "Cursor.png",
				Depth = "10"
			}
		},
		{
			Name = "CURSOR",
			Arguments = {
			}
		}
	}		
}

Entity4 = {
	Name = "FullscreenButtonOff",
	Components = {
		{
			Name = "BUTTON",
			Arguments = {
                OverlayName= "buttonfullscreenoff",
				XPos = "50",
                YPos = "25",
                Width = "55",
                Height = "9",
                Texture1 = "fullscreenoff_red.png",
                Texture2 = "fullscreenoff_darkred.png",
                Texture3 = "fullscreenoff_darkred.png",
                Depth = "2"
			}
		},
        {
            Name = "BEHAVIOUR",
			Arguments = {
                Script= "ButtonScript",
			}
        }
	}	
}

Entity5 = {
	Name = "FullscreenButtonOn",
	Components = {
		{
			Name = "BUTTON",
			Arguments = {
                OverlayName= "buttonfullscreenon",
				XPos = "50",
                YPos = "25",
                Width = "50",
                Height = "9",
                Texture1 = "fullscreenon_green.png",
                Texture2 = "fullscreenon_darkgreen.png",
                Texture3 = "fullscreenon_darkgreen.png",
                Depth = "2"
			}
		},
        {
            Name = "BEHAVIOUR",
			Arguments = {
                Script= "ButtonScript",
			}
        }
	}
}

Entity6 = {
	Name = "BackButton",
	Components = {
		{
			Name = "BUTTON",
			Arguments = {
                OverlayName= "button",
				XPos = "5",
                YPos = "9",
                Width = "10",
                Height = "13",
                Texture1 = "atras_white.png",
                Texture2 = "atras_red.png",
                Texture3 = "atras_darkred.png",
                Depth = "2"
			}
		},
        {
            Name = "BEHAVIOUR",
			Arguments = {
                Script= "ButtonScript"
			}
        }
	}	
}

Entity7 = {
	Name = "ResolutionsPreviousButton",
	Components = {
		{
			Name = "BUTTON",
			Arguments = {
                OverlayName= "resolutionbuttonprevious",
				XPos = "25",
                YPos = "50",
                Width = "10",
                Height = "13",
				Texture1 = "atras_white.png",
                Texture2 = "atras_red.png",
                Texture3 = "atras_darkred.png",
                Depth = "2"
			}
		},
        {
            Name = "BEHAVIOUR",
			Arguments = {
                Script= "ButtonScript",
			}
        }
	}	
}

Entity8 = {
	Name = "ResolutionsText",
	Components = {
		{
			Name = "TEXT",
			Arguments = {
                OverlayName= "resolutiontext",
				XPos = "50",
                YPos = "45",
                Tam = "9",
                Text = "640x460",
                Font = "DooM.ttf",
                Color = "90|90|90",
                Depth = "1"
			}
		}
	}	
}

Entity9 = {
	Name = "ResolutionsForwardButton",
	Components = {
		{
			Name = "BUTTON",
			Arguments = {
                OverlayName= "resolutionbuttonforward",
				XPos = "75",
                YPos = "50",
                Width = "10",
                Height = "13",
				Texture1 = "avance_white.png",
                Texture2 = "avance_red.png",
                Texture3 = "avance_darkred.png",
                Depth = "2"
			}
		},
        {
            Name = "BEHAVIOUR",
			Arguments = {
                Script= "ButtonScript",
			}
        }
	}	
}

Entity10 = {
	Name = "Wall",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "HazardousWall"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "6.635709285736084|7.499549865722656|10.917777061462402",
				Rotation = "false|0.6823428869247437|-0.6832689046859741|0.18511664867401123|0.18243788182735443",
				Scale = "-7.888233184814453|-0.13727302849292755|-5.59731388092041"
			}
		}
	}
}

Entity11 = {
	Name = "Wall",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "HazardousWall"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "6.997795581817627|7.499549865722656|-9.030996322631836",
				Rotation = "false|0.19475239515304565|-0.19752372801303864|0.6796554327011108|0.6790613532066345",
				Scale = "-7.888238430023193|-0.13727302849292755|-5.59731388092041"
			}
		}
	}
}

Entity12 = {
	Name = "Wall",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "HazardousWall"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-5.430561065673828|7.499549865722656|10.698763847351074",
				Rotation = "false|0.19475239515304565|-0.19752372801303864|0.6796554327011108|0.6790613532066345",
				Scale = "-7.888238430023193|-0.13727302849292755|-5.59731388092041"
			}
		}
	}
}

Entity13 = {
	Name = "Floor1",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Floor"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.8228198289871216|1.7865326404571533|0.7102036476135254",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "15.294673919677734|18.7946720123291|0.28266042470932007"
			}
		}
	}
}

Entity14 = {
	Name = "Cube.002",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "1.6801811456680298|4.428697109222412|0.5540367364883423",
				Rotation = "false|0.7030217051506042|-0.7030218839645386|-0.07589713484048843|-0.07589715719223022",
				Scale = "0.6255058646202087|0.6564507484436035|0.6564506888389587"
			}
		}
	}
}

Entity15 = {
	Name = "Cube.001",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "1.6801811456680298|2.9162464141845703|0.5540367364883423",
				Rotation = "false|0.6982442140579224|-0.6982442736625671|0.1116017997264862|0.1116018071770668",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		}
	}
}

Entity16 = {
	Name = "Sun",
	Components = {
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "9.962356567382812|-0.608795166015625|10.804308891296387",
				Rotation = "false|0.584906816482544|-0.7914972305297852|-0.08224325627088547|-0.15701015293598175",
				Scale = "0.6571059823036194|0.6571060419082642|0.6571060419082642"
			}
		}
	}
}

Entity17 = {
	Name = "Cube",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "CatWalk"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "6.014024257659912|7.788323402404785|10.178730964660645",
				Rotation = "false|0.6824097037315369|-0.6824098825454712|0.18524812161922455|0.18524816632270813",
				Scale = "0.8145411014556885|0.8145411014556885|0.814540684223175"
			}
		}
	}
}

Entity18 = {
	Name = "Cube.003",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "CatWalk"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-4.450030326843262|7.788323402404785|-8.481858253479004",
				Rotation = "false|0.18524813652038574|-0.18524813652038574|-0.6824097633361816|-0.6824098229408264",
				Scale = "0.814540684223175|0.814540684223175|0.814540684223175"
			}
		}
	}
}

Entity19 = {
	Name = "Cylinder.001",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "DangerousBarrel"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "4.11507511138916|2.774369955062866|-5.571362018585205",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "0.4192843735218048|0.4192843735218048|0.42240726947784424"
			}
		}
	}
}

Entity20 = {
	Name = "Cylinder.002",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "DangerousBarrel"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "11.818910598754883|2.9453415870666504|5.358007907867432",
				Rotation = "false|0.3182870149612427|-0.31828707456588745|-0.6314216256141663|-0.6314218044281006",
				Scale = "0.5248204469680786|0.5248204469680786|0.5248204469680786"
			}
		}
	}
}

Entity21 = {
	Name = "Cylinder.003",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "DangerousBarrel"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "12.613204002380371|2.945341110229492|3.931981086730957",
				Rotation = "false|0.6993336081504822|-0.699333667755127|-0.10455840826034546|-0.10455842316150665",
				Scale = "0.5248204469680786|0.5248204469680786|0.5248204469680786"
			}
		}
	}
}

Entity22 = {
	Name = "Cylinder.004",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "DangerousBarrel"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "12.520537376403809|4.751825332641602|4.854357719421387",
				Rotation = "false|0.6022876501083374|-0.6022877097129822|0.37047210335731506|0.3704720735549927",
				Scale = "0.5248205065727234|0.5248205065727234|0.5248204469680786"
			}
		}
	}
}

Entity23 = {
	Name = "Cube.004",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "13.137256622314453|4.133596420288086|2.5489296913146973",
				Rotation = "false|0.09460096061229706|-0.6604019999504089|-0.6871870160102844|-0.2875654101371765",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		}
	}
}

Entity24 = {
	Name = "Cylinder.005",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "DangerousBarrel"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-4.142608642578125|2.8020119667053223|3.068695068359375",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "0.4389641582965851|0.4389641582965851|0.4389641582965851"
			}
		}
	}
}

Entity25 = {
	Name = "Cube.005",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.2351142168045044|2.725639820098877|-7.639638423919678",
				Rotation = "false|0.6797195672988892|-0.6797196865081787|0.1948876529932022|0.1948876678943634",
				Scale = "0.6255058646202087|0.6564507484436035|0.6564506888389587"
			}
		}
	}
}

Entity26 = {
	Name = "Cube.006",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-5.179019927978516|2.9162464141845703|-2.3572826385498047",
				Rotation = "false|0.604570746421814|-0.6045708060264587|0.36673447489738464|0.36673447489738464",
				Scale = "1.9370685815811157|0.9383481740951538|0.8470563292503357"
			}
		}
	}
}

Entity27 = {
	Name = "Cube.007",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.6557600498199463|2.4009904861450195|8.980277061462402",
				Rotation = "false|0.7051228880882263|-0.7051228880882263|-0.05293139070272446|-0.05293139070272446",
				Scale = "2.1980843544006348|0.7364873886108398|0.3317997455596924"
			}
		}
	}
}

Entity28 = {
	Name = "Cube.008",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.9488237500190735|3.0645904541015625|9.07736873626709",
				Rotation = "false|0.6906960010528564|-0.6906960606575012|-0.15145625174045563|-0.15145625174045563",
				Scale = "2.1980843544006348|0.7364872694015503|0.3317997455596924"
			}
		}
	}
}

Entity29 = {
	Name = "Cube.009",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.9488237500190735|3.7281901836395264|9.07736873626709",
				Rotation = "false|0.7054849863052368|-0.7054850459098816|0.04786330461502075|0.04786330461502075",
				Scale = "2.1980843544006348|0.7364872694015503|0.3317997455596924"
			}
		}
	}
}

Entity30 = {
	Name = "A_LIGHT",
	Components = {
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.6480690240859985|1.407318353652954|-0.6305416822433472",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "0.6571059823036194|0.6571059823036194|0.6571059823036194"
			}
		},
		{
			Name = "LIGHT",
			Arguments = {
				LightType = "LT_POINT",
				DiffuseColor = "1|1|1",
				SpecularColor = "0|0|0"
			}
		}
	}
}

Entity32 = {
	Name = "Wall",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "HazardousWall"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-5.050967216491699|7.493031978607178|-9.219793319702148",
				Rotation = "false|0.6823428869247437|-0.6832689046859741|0.18511664867401123|0.18243788182735443",
				Scale = "-7.888233184814453|-0.13727302849292755|-5.59731388092041"
			}
		}
	}
}

Entity33 = {
	Name = "Wall",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "HazardousWall"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-18.647233963012695|7.499549865722656|10.917777061462402",
				Rotation = "false|0.6823428869247437|-0.6832689046859741|0.18511664867401123|0.18243788182735443",
				Scale = "-7.888233184814453|-0.13727302849292755|-5.59731388092041"
			}
		}
	}
}

Entity34 = {
	Name = "Wall",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "HazardousWall"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-18.28514862060547|7.499549865722656|-9.030996322631836",
				Rotation = "false|0.14693887531757355|-0.14974486827850342|0.6915699243545532|0.691170334815979",
				Scale = "-7.888238430023193|-0.13727302849292755|-5.59731388092041"
			}
		}
	}
}

Entity35 = {
	Name = "Wall",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "HazardousWall"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-28.664796829223633|7.69948148727417|8.096073150634766",
				Rotation = "false|0.3513578772544861|-0.3539072871208191|0.6135207414627075|0.6122822761535645",
				Scale = "-8.268681526184082|-0.13727301359176636|-5.59731388092041"
			}
		}
	}
}

Entity36 = {
	Name = "Floor.001",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Floor"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-29.766529083251953|1.7865326404571533|0.7102036476135254",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "15.294673919677734|18.7946720123291|0.28266042470932007"
			}
		}
	}
}

Entity37 = {
	Name = "Cube.010",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "CatWalk"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-19.268918991088867|7.788323402404785|10.178730964660645",
				Rotation = "false|0.6824097037315369|-0.6824098825454712|0.18524812161922455|0.18524816632270813",
				Scale = "0.8145411014556885|0.8145411014556885|0.814540684223175"
			}
		}
	}
}

Entity38 = {
	Name = "Wall",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "HazardousWall"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-27.58919334411621|7.692963123321533|-5.156338691711426",
				Rotation = "false|0.6365441083908081|-0.6379477977752686|0.3076876699924469|0.3052254021167755",
				Scale = "-9.615391731262207|-0.13727301359176636|-5.59731388092041"
			}
		}
	}
}

Entity39 = {
	Name = "Wall",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "HazardousWall"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "19.9129638671875|7.499549865722656|10.698763847351074",
				Rotation = "false|0.19475239515304565|-0.19752372801303864|0.6796554327011108|0.6790613532066345",
				Scale = "-7.888238430023193|-0.13727302849292755|-5.59731388092041"
			}
		}
	}
}

Entity40 = {
	Name = "Floor.002",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Floor"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "31.412168502807617|1.7865326404571533|0.7102036476135254",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "15.294673919677734|18.7946720123291|0.28266042470932007"
			}
		}
	}
}

Entity41 = {
	Name = "Cube.013",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "CatWalk"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "20.89349365234375|7.788323402404785|-8.481858253479004",
				Rotation = "false|0.18524813652038574|-0.18524813652038574|-0.6824097633361816|-0.6824098229408264",
				Scale = "0.814540684223175|0.814540684223175|0.814540684223175"
			}
		}
	}
}

Entity42 = {
	Name = "Wall",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "HazardousWall"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "20.292556762695312|7.493031978607178|-9.219793319702148",
				Rotation = "false|0.6823428869247437|-0.6832689046859741|0.18511664867401123|0.18243788182735443",
				Scale = "-7.888233184814453|-0.13727302849292755|-5.59731388092041"
			}
		}
	}
}

Entity43 = {
	Name = "Wall",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "HazardousWall"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "26.679767608642578|7.697965145111084|10.619329452514648",
				Rotation = "false|0.4989292323589325|-0.5010684728622437|0.5009287595748901|0.4990695118904114",
				Scale = "-7.888238430023193|-0.13727302849292755|-5.59731388092041"
			}
		}
	}
}

Entity44 = {
	Name = "Wall",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "HazardousWall"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "26.679767608642578|7.697965145111084|-5.157273769378662",
				Rotation = "false|0.4989292323589325|-0.5010684728622437|0.5009287595748901|0.4990695118904114",
				Scale = "-7.888238430023193|-0.13727302849292755|-5.59731388092041"
			}
		}
	}
}

Entity45 = {
	Name = "Cylinder.006",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "DangerousBarrel"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "25.435373306274414|2.9453415870666504|-6.722875118255615",
				Rotation = "false|0.6125204563140869|-0.6125204563140869|-0.35329684615135193|-0.3532969057559967",
				Scale = "0.5248204469680786|0.5248204469680786|0.5248204469680786"
			}
		}
	}
}

Entity46 = {
	Name = "Cylinder.007",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "DangerousBarrel"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "24.44333839416504|2.945341110229492|-8.019146919250488",
				Rotation = "false|0.6420567035675049|-0.6420568227767944|0.2962484061717987|0.2962484359741211",
				Scale = "0.5248204469680786|0.5248204469680786|0.5248204469680786"
			}
		}
	}
}

Entity47 = {
	Name = "Cylinder.008",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "DangerousBarrel"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "25.252614974975586|4.751825332641602|-7.566997528076172",
				Rotation = "false|0.3003089427947998|-0.3003090023994446|0.6401675939559937|0.6401675939559937",
				Scale = "0.5248205065727234|0.5248205065727234|0.5248204469680786"
			}
		}
	}
}

Entity48 = {
	Name = "Cube.011",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "23.383163452148438|4.133596420288086|-9.050403594970703",
				Rotation = "false|0.4560962915420532|-0.7099079489707947|-0.5226389765739441|0.1218826100230217",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		}
	}
}

Entity49 = {
	Name = "Cube.012",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "23.616527557373047|2.9162464141845703|8.545625686645508",
				Rotation = "false|0.604570746421814|-0.6045708060264587|0.36673447489738464|0.36673447489738464",
				Scale = "1.9370685815811157|0.9383481740951538|0.8470563292503357"
			}
		}
	}
}

Entity50 = {
	Name = "Cube.014",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "21.159374237060547|2.9162464141845703|-0.26442527770996094",
				Rotation = "false|0.3603763282299042|-0.3603764772415161|0.6083821058273315|0.6083822250366211",
				Scale = "1.9370685815811157|0.9383481740951538|0.8470563292503357"
			}
		}
	}
}

Entity51 = {
	Name = "Cylinder.009",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "DangerousBarrel"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-19.015748977661133|2.7901813983917236|3.7422611713409424",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "0.4286847412586212|0.4286847412586212|0.43187761306762695"
			}
		}
	}
}

Entity52 = {
	Name = "Cylinder.010",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "DangerousBarrel"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-19.66368865966797|2.7627623081207275|2.028904676437378",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "0.4123821556568146|0.4123821556568146|0.41545361280441284"
			}
		}
	}
}

Entity53 = {
	Name = "Cylinder.011",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "DangerousBarrel"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-19.708887100219727|2.8192005157470703|-0.9980835914611816",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "0.445939302444458|0.445939302444458|0.4492607116699219"
			}
		}
	}
}

Entity54 = {
	Name = "Cube.015",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-19.308368682861328|3.873034954071045|1.9956581592559814",
				Rotation = "false|0.7030217051506042|-0.7030218839645386|-0.07589713484048843|-0.07589715719223022",
				Scale = "0.6599737405776978|0.6926238536834717|0.4277225732803345"
			}
		}
	}
}

Entity55 = {
	Name = "Cube.016",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-19.308368682861328|4.728479385375977|1.9956581592559814",
				Rotation = "false|0.7049946188926697|-0.704994797706604|0.05461214482784271|0.05461215600371361",
				Scale = "0.40755990147590637|0.42772260308265686|0.4277225732803345"
			}
		}
	}
}

Entity56 = {
	Name = "Cube.017",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-21.943256378173828|4.428701400756836|8.404542922973633",
				Rotation = "false|0.6354477405548096|-0.6354479193687439|-0.310170978307724|-0.31017109751701355",
				Scale = "0.6255058646202087|0.6564507484436035|0.6564506888389587"
			}
		}
	}
}

Entity57 = {
	Name = "Cube.018",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-21.943256378173828|2.916250705718994|8.404542922973633",
				Rotation = "false|0.6946395635604858|-0.6946396231651306|-0.13219621777534485|-0.13219621777534485",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		}
	}
}

Entity58 = {
	Name = "Cube.019",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-24.583890914916992|4.428698539733887|-4.364519119262695",
				Rotation = "false|0.7069522738456726|-0.7069525122642517|-0.014775741845369339|-0.014775753952562809",
				Scale = "0.6255058646202087|0.6564507484436035|0.6564506888389587"
			}
		}
	}
}

Entity59 = {
	Name = "Cube.020",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-24.583890914916992|2.916248321533203|-4.364519119262695",
				Rotation = "false|0.6859673857688904|-0.6859673857688904|0.17160636186599731|0.1716063916683197",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		}
	}
}

Entity60 = {
	Name = "Cube.021",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-26.89447784423828|4.006252288818359|2.9490795135498047",
				Rotation = "false|0.12335643917322159|0.696262776851654|-0.6962636113166809|-0.12336256355047226",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		}
	}
}

Entity61 = {
	Name = "Cube.022",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-12.7322416305542|4.006254196166992|3.315239191055298",
				Rotation = "false|0.12335643917322159|0.696262776851654|-0.6962636113166809|-0.12336256355047226",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		}
	}
}

Entity62 = {
	Name = "Cube.023",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-12.433406829833984|4.006251335144043|-2.0262086391448975",
				Rotation = "false|0.42586004734039307|0.5644811391830444|-0.5644848942756653|-0.4258650541305542",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		}
	}
}

Entity63 = {
	Name = "Cube.024",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "Crate"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-12.845291137695312|7.811142921447754|3.72383189201355",
				Rotation = "false|0.4630751311779022|0.5343753695487976|-0.5343795418739319|-0.4630798101425171",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		}
	}
}

Entity64 = {
	Name = "ResolutionsTitle",
	Components = {
		{
			Name = "IMAGE",
			Arguments = {
                OverlayName= "resolutionstitle",
				XPos = "50",
				YPos = "40",
				Width = "45",
				Height = "9",
				Texture = "screensize.png",
				Depth = "1"
			}
		}
	}	
}

Entity65 = {
	Name = "SoundTitle",
	Components = {
		{
			Name = "IMAGE",
			Arguments = {
                OverlayName= "soundtitle",
				XPos = "50",
				YPos = "65",
				Width = "45",
				Height = "9",
				Texture = "soundvolume.png",
				Depth = "1"
			}
		}
	}	
}

Entity66 = {
	Name = "VolumeDownButton",
	Components = {
		{
			Name = "BUTTON",
			Arguments = {
                OverlayName= "volumebuttondown",
				XPos = "18",
                YPos = "76",
                Width = "10",
                Height = "13",
				Texture1 = "atras_white.png",
                Texture2 = "atras_red.png",
                Texture3 = "atras_darkred.png",
                Depth = "2"
			}
		},
        {
            Name = "BEHAVIOUR",
			Arguments = {
                Script= "ButtonScript",
			}
        }
	}	
}

Entity67 = {
	Name = "VolumeBar",
	Components = {
		{
			Name = "BAR",
			Arguments = {
                OverlayName= "volumebarbar",
				XPos = "50",
                YPos = "75.5",
                Width = "50",
                Height = "5",
                Texture = "volumebar.png",
                Depth = "3"
			}
		},
		{
			Name = "IMAGE",
			Arguments = {
				OverlayName= "volumebarbackground",
				XPos = "50",
                YPos = "75",
                Width = "50",
                Height = "10",
                Texture = "volumebarbackground.png",
                Depth = "2"
			}
		}
	}	
}

Entity68 = {
	Name = "VolumeUpButton",
	Components = {
		{
			Name = "BUTTON",
			Arguments = {
                OverlayName= "volumebuttonup",
				XPos = "82",
                YPos = "76",
                Width = "10",
                Height = "13",
				Texture1 = "avance_white.png",
                Texture2 = "avance_red.png",
                Texture3 = "avance_darkred.png",
                Depth = "2"
			}
		},
        {
            Name = "BEHAVIOUR",
			Arguments = {
                Script= "ButtonScript",
			}
        }
	}	
}

Entity69 = {
	Name = "BlurredBackground",
	Components = {
		{
			Name = "IMAGE",
			Arguments = {
				OverlayName = "backgroundimg",
				XPos = "50",
                YPos = "50",
                Width = "100",
                Height = "100",
                Texture = "blurtransparentbg.png",
                Depth = "0"
			}
		}
	}
}

Entities = { Entity1, Entity2, Entity3, Entity4, Entity5, Entity6, Entity7, Entity8, Entity9, Entity10, Entity11, Entity12, Entity13, Entity14, Entity15, Entity16, Entity17, Entity18, Entity19, Entity20, Entity21, Entity22, Entity23, Entity24, Entity25, Entity26, Entity27, Entity28, Entity29, Entity30, Entity32, Entity33, Entity34, Entity35, Entity36, Entity37, Entity38, Entity39, Entity40, Entity41, Entity42, Entity43, Entity44, Entity45, Entity46, Entity47, Entity48, Entity49, Entity50, Entity51, Entity52, Entity53, Entity54, Entity55, Entity56, Entity57, Entity58, Entity59, Entity60, Entity61, Entity62, Entity63, Entity64, Entity65, Entity66, Entity67, Entity68, Entity69 }

CollisionLayers = {
	Layers = {
		DEFAULT = ""
	}
}