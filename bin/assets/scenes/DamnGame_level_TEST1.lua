Entity1 = {
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
				Position = "6.635709285736084|7.499549865722656|22.059398651123047",
				Rotation = "false|0.6823428869247437|-0.6832689046859741|0.18511664867401123|0.18243788182735443",
				Scale = "-7.888233184814453|-0.13727302849292755|-5.59731388092041"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "15.776466369628906",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity2 = {
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
				Position = "6.997795581817627|7.499549865722656|-20.139755249023438",
				Rotation = "false|0.19475239515304565|-0.19752372801303864|0.6796554327011108|0.6790613532066345",
				Scale = "-7.888238430023193|-0.13727302849292755|-5.59731388092041"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "1.999999879101738|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "15.77647590637207",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity3 = {
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
				Position = "-5.430561065673828|7.499549865722656|21.84038543701172",
				Rotation = "false|0.19475239515304565|-0.19752372801303864|0.6796554327011108|0.6790613532066345",
				Scale = "-7.888238430023193|-0.13727302849292755|-5.59731388092041"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "1.999999879101738|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "15.77647590637207",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity4 = {
	Name = "Floor",
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
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "37.5893440246582",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "FLOOR",
				Trigger = "false"
			}
		}
	}
}

Entity5 = {
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
				Position = "-7.430619716644287|4.428697109222412|-11.277924537658691",
				Rotation = "false|0.7030217051506042|-0.7030218839645386|-0.07589713484048843|-0.07589715719223022",
				Scale = "0.6255058646202087|0.6564507484436035|0.6564506888389587"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0000001815967",
				PosOffset = "0|0|0",
				Radius = "1.3129016160964966",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity6 = {
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
				Position = "-7.430619716644287|2.9162464141845703|-11.277924537658691",
				Rotation = "false|0.6982442140579224|-0.6982442736625671|0.1116017997264862|0.1116018071770668",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "3.8741366863250732",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity7 = {
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

Entity8 = {
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
				Position = "6.014024257659912|7.788323402404785|21.320354461669922",
				Rotation = "false|0.6824097037315369|-0.6824098825454712|0.18524812161922455|0.18524816632270813",
				Scale = "0.8145411014556885|0.8145411014556885|0.814540684223175"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "13.066710220864861|1.2687056120330242|2.2541460640381357",
				PosOffset = "0|0|0",
				Radius = "10.643372535705566",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity9 = {
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
				Position = "-4.450030326843262|7.788323402404785|-19.590618133544922",
				Rotation = "false|0.18524813652038574|-0.18524813652038574|-0.6824097633361816|-0.6824098229408264",
				Scale = "0.814540684223175|0.814540684223175|0.814540684223175"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "13.066709889156996|1.2687056120330242|2.2541460478679323",
				PosOffset = "0|0|0",
				Radius = "10.643366813659668",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity10 = {
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
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "3.1669189142622827|3.4935205052535565|3.1669189142622827",
				PosOffset = "0|0|0",
				Radius = "1.4756884574890137",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity11 = {
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
				Position = "5.428023815155029|2.9453415870666504|-14.295825004577637",
				Rotation = "false|0.7066218852996826|-0.7066220641136169|0.026180341839790344|0.026180321350693703",
				Scale = "0.5248204469680786|0.5248204469680786|0.5248204469680786"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "3.1669189846798864|3.4935204052776223|3.1669189846798864",
				PosOffset = "0|0|0",
				Radius = "1.8334709405899048",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity12 = {
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
				Position = "3.829176902770996|2.945341110229492|-13.9669771194458",
				Rotation = "false|0.38649672269821167|-0.38649675250053406|0.5921319723129272|0.5921319723129272",
				Scale = "0.5248204469680786|0.5248204469680786|0.5248204469680786"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "3.1669189846798864|3.4935204052776223|3.1669189846798864",
				PosOffset = "0|0|0",
				Radius = "1.8334709405899048",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity13 = {
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
				Position = "4.588517665863037|4.751825332641602|-14.498735427856445",
				Rotation = "false|0.08575940877199173|-0.08575934916734695|-0.7018869519233704|-0.7018870115280151",
				Scale = "0.5248205065727234|0.5248205065727234|0.5248204469680786"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "3.1669186250081913|3.4935204052776223|3.1669186250081913",
				PosOffset = "0|0|0",
				Radius = "1.8334709405899048",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity14 = {
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
				Position = "2.037050724029541|4.133596420288086|-13.875418663024902",
				Rotation = "false|0.6051543951034546|-0.6277162432670593|-0.3390626907348633|0.3532661497592926",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "1.999999876917828|2.0000001407336034|2.0",
				PosOffset = "0|0|0",
				Radius = "3.874136447906494",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity15 = {
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
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "3.166918920812566|3.493520384993258|3.166918920812566",
				PosOffset = "0|0|0",
				Radius = "1.5335302352905273",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity16 = {
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
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "1.312901496887207",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity17 = {
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
				Position = "11.110393524169922|2.9162468910217285|-0.2609117031097412",
				Rotation = "false|0.604570746421814|-0.6045708060264587|0.36673447489738464|0.36673447489738464",
				Scale = "1.9370685815811157|0.9383481740951538|0.8470563292503357"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "3.8741371631622314",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity18 = {
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
				Position = "-1.539143681526184|2.4009904861450195|-12.929691314697266",
				Rotation = "false|0.7051228880882263|-0.7051228880882263|-0.05293139070272446|-0.05293139070272446",
				Scale = "2.1980843544006348|0.7364873886108398|0.3317997455596924"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "4.3961687088012695",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity19 = {
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
				Position = "-1.2460800409317017|3.0645904541015625|-12.832599639892578",
				Rotation = "false|0.6906960010528564|-0.6906960606575012|-0.15145625174045563|-0.15145625174045563",
				Scale = "2.1980843544006348|0.7364872694015503|0.3317997455596924"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "4.3961687088012695",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity20 = {
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
				Position = "-1.2460800409317017|3.7281899452209473|-12.832599639892578",
				Rotation = "false|0.7054849863052368|-0.7054850459098816|0.04786330461502075|0.04786330461502075",
				Scale = "2.1980843544006348|0.7364872694015503|0.3317997455596924"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "4.3961687088012695",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity21 = {
	Name = "AUI_HEALTH_BAR",
	Components = {
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.6480690240859985|1.407318353652954|0.683670163154602",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "0.6571059823036194|0.6571059823036194|0.6571059823036194"
			}
		},
		{
			Name = "BAR",
			Arguments = {
				OverlayName = "HealthBar",
				XPos = "18",
				YPos = "24",
				Width = "20",
				Height = "4",
				Texture = "HealthBar.png",
				Depth = "2"
			}
		},
		{
			Name = "IMAGE",
			Arguments = {
				OverlayName = "BackBarImage",
				XPos = "18",
				YPos = "24",
				Width = "22",
				Height = "7",
				Texture = "BackBar.png",
				Depth = "1"
			}
		}
	}
}

Entity22 = {
	Name = "AUI_AMMO_TEXT",
	Components = {
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.6480690240859985|1.407318353652954|0.683670163154602",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "0.6571059823036194|0.6571059823036194|0.6571059823036194"
			}
		},
		{
			Name = "TEXT",
			Arguments = {
				OverlayName = "AmmoText",
				XPos = "95",
				YPos = "90",
				Width = "30",
				Depth = "1",
				Tam = "3.5",
				Text = "XX/XX",
				Font = "01-digit2000.regular.ttf",
				Color = "1|129|255"
			}
		}
	}
}

Entity23 = {
	Name = "AUI_GUN_IMAGE",
	Components = {
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.6480690240859985|1.407318353652954|0.683670163154602",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "0.6571059823036194|0.6571059823036194|0.6571059823036194"
			}
		},
		{
			Name = "IMAGE",
			Arguments = {
				OverlayName = "GunImage",
				XPos = "79",
				YPos = "92",
				Width = "23",
				Height = "10",
				Texture = "Pistol.png",
				Depth = "2"
			}
		}
	}
}

Entity24 = {
	Name = "AUI_TIME_TEXT",
	Components = {
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.6480690240859985|1.407318353652954|0.683670163154602",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "0.6571059823036194|0.6571059823036194|0.6571059823036194"
			}
		},
		{
			Name = "TEXT",
			Arguments = {
				OverlayName = "TimeText",
				XPos = "82",
				YPos = "30",
				Depth = "1",
				Tam = "3",
				Text = "TIME: XXXX",
				Font = "01-digit2000.regular.ttf",
				Color = "0|0|0"
			}
		}
	}
}

Entity25 = {
	Name = "AUI_ENEMIES_LEFT_TEXT",
	Components = {
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.6480690240859985|1.407318353652954|0.683670163154602",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "0.6571059823036194|0.6571059823036194|0.6571059823036194"
			}
		},
		{
			Name = "TEXT",
			Arguments = {
				OverlayName = "EnemiesLeftText",
				XPos = "80",
				YPos = "20",
				Depth = "1",
				Tam = "3",
				Text = "ENEMIES: XXXXXX",
				Font = "01-digit2000.regular.ttf",
				Color = "0|0|0"
			}
		}
	}
}

Entity26 = {
	Name = "UI_MANAGER",
	Components = {
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.6480690240859985|1.407318353652954|0.683670163154602",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "0.6571059823036194|0.6571059823036194|0.6571059823036194"
			}
		},
		{
			Name = "UIMANAGER",
			Arguments = {
			}
		}
	}
}

Entity27 = {
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

Entity28 = {
	Name = "AUI_SCORE_TEXT",
	Components = {
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.6480690240859985|1.407318353652954|0.683670163154602",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "0.6571059823036194|0.6571059823036194|0.6571059823036194"
			}
		},
		{
			Name = "TEXT",
			Arguments = {
				OverlayName = "ScoreText",
				XPos = "81",
				YPos = "25",
				Depth = "1",
				Tam = "3",
				Text = "SCORE: XXXX",
				Font = "01-digit2000.regular.ttf",
				Color = "0|0|0"
			}
		}
	}
}

Entity29 = {
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
				Position = "-5.050967216491699|7.493031978607178|-20.32855224609375",
				Rotation = "false|0.6823428869247437|-0.6832689046859741|0.18511664867401123|0.18243788182735443",
				Scale = "-7.888233184814453|-0.13727302849292755|-5.59731388092041"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "15.776466369628906",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity30 = {
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
				Position = "-14.037086486816406|7.499549865722656|8.53976821899414",
				Rotation = "false|0.5511497855186462|-0.5495287179946899|-0.4428247809410095|-0.4451497793197632",
				Scale = "-9.924290657043457|-0.13913372159004211|-5.597339153289795"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "1.9999998078100794|2.0|1.999999785800868",
				PosOffset = "0|0|0",
				Radius = "19.84857940673828",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity31 = {
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
				Position = "-14.045703887939453|7.499549865722656|-8.846429824829102",
				Rotation = "false|0.4347235858440399|-0.4326118230819702|-0.5575620532035828|-0.5594524145126343",
				Scale = "-7.888238430023193|-0.13727302849292755|-5.59731388092041"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "15.776476860046387",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity32 = {
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
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "37.5893440246582",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "FLOOR",
				Trigger = "false"
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
				Position = "15.293509483337402|7.499549865722656|10.571549415588379",
				Rotation = "false|0.4371759295463562|-0.43507251143455505|-0.555641233921051|-0.5575409531593323",
				Scale = "-8.63253402709961|-0.13809359073638916|-5.597323417663574"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.000000215812495",
				PosOffset = "0|0|0",
				Radius = "17.26506805419922",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity34 = {
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
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "37.5893440246582",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "FLOOR",
				Trigger = "false"
			}
		}
	}
}

Entity35 = {
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
				Position = "14.450617790222168|7.788323402404785|-5.556682586669922",
				Rotation = "false|0.447288453578949|-0.44728848338127136|0.5476614236831665|0.5476614236831665",
				Scale = "0.814540684223175|0.814540684223175|0.814540684223175"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "13.066709889156996|1.2687056120330242|2.2541460478679323",
				PosOffset = "0|0|0",
				Radius = "10.643366813659668",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity36 = {
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
				Position = "15.310534477233887|7.493031978607178|-6.706588268280029",
				Rotation = "false|0.5475155711174011|-0.5458755493164062|-0.4473104178905487|-0.4496220648288727",
				Scale = "-9.89550495147705|-0.13998158276081085|-5.597338676452637"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.000000212901739",
				PosOffset = "0|0|0",
				Radius = "19.7910099029541",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity37 = {
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
				Position = "9.10203742980957|2.9162464141845703|4.331490516662598",
				Rotation = "false|0.604570746421814|-0.6045708060264587|0.36673447489738464|0.36673447489738464",
				Scale = "1.9370685815811157|0.9383481740951538|0.8470563292503357"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "3.8741371631622314",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity38 = {
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
				Position = "8.487479209899902|2.9162464141845703|8.234162330627441",
				Rotation = "false|0.3603763282299042|-0.3603764772415161|0.6083821058273315|0.6083822250366211",
				Scale = "1.9370685815811157|0.9383481740951538|0.8470563292503357"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "3.8741371631622314",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity39 = {
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
				Position = "1.0020084381103516|2.7901813983917236|20.329833984375",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "0.4286847412586212|0.4286847412586212|0.43187761306762695"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "3.1669190372012546|3.493520574398292|3.1669190372012546",
				PosOffset = "0|0|0",
				Radius = "1.5087733268737793",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity40 = {
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
				Position = "9.53183650970459|2.868696451187134|1.6939165592193604",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "0.5071452260017395|0.5071452260017395|0.5109224915504456"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "3.166918905069469|3.493520482201231|3.166918905069469",
				PosOffset = "0|0|0",
				Radius = "1.784918189048767",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity41 = {
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
				Position = "12.749418258666992|2.8192005157470703|-11.600852966308594",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "0.445939302444458|0.445939302444458|0.4492607116699219"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "3.1669189293227937|3.4935205292474376|3.1669189293227937",
				PosOffset = "0|0|0",
				Radius = "1.569501519203186",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity42 = {
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
				Position = "9.968807220458984|4.234103202819824|1.653029441833496",
				Rotation = "false|0.7030217051506042|-0.7030218839645386|-0.07589713484048843|-0.07589715719223022",
				Scale = "0.8116319179534912|0.8517849445343018|0.5260108113288879"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.000000146876049|2.0|2.0000001399523324",
				PosOffset = "0|0|0",
				Radius = "1.703570008277893",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity43 = {
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
				Position = "9.968807220458984|5.286124229431152|1.653029441833496",
				Rotation = "false|0.7049946188926697|-0.704994797706604|0.05461214482784271|0.05461215600371361",
				Scale = "0.5012148022651672|0.5260108709335327|0.5260108113288879"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "1.0520217418670654",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity44 = {
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
				Position = "13.919239044189453|4.428701400756836|-2.762199878692627",
				Rotation = "false|0.7056869864463806|-0.7056871652603149|0.044785697013139725|0.04478568211197853",
				Scale = "0.6255058646202087|0.6564507484436035|0.6564506888389587"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "1.312901496887207",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity45 = {
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
				Position = "13.919239044189453|2.916250705718994|-2.762199878692627",
				Rotation = "false|0.6690874695777893|-0.6690874695777893|0.2287399172782898|0.228739932179451",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "3.8741366863250732",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity46 = {
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
				Position = "9.760968208312988|4.428698539733887|-16.09938621520996",
				Rotation = "false|0.7069522738456726|-0.7069525122642517|-0.014775706455111504|-0.01477578841149807",
				Scale = "0.6255058646202087|0.6564507484436035|0.6564506888389587"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0000001905806104|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "1.312901496887207",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity47 = {
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
				Position = "9.760968208312988|2.916248083114624|-16.09938621520996",
				Rotation = "false|0.6859673857688904|-0.6859673857688904|0.17160636186599731|0.1716063916683197",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "3.8741366863250732",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity48 = {
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
				Position = "6.961585998535156|4.006252288818359|-14.897586822509766",
				Rotation = "false|0.18288034200668335|0.6830511689186096|-0.6830455660820007|-0.18287883698940277",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "3.8741366863250732",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity49 = {
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
				Position = "-5.040890693664551|4.00625467300415|-12.845011711120605",
				Rotation = "false|0.18288034200668335|0.6830511689186096|-0.6830455660820007|-0.18287883698940277",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "3.8741366863250732",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity50 = {
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
				Position = "-10.931574821472168|4.006251335144043|-2.8278303146362305",
				Rotation = "false|0.43343400955200195|0.5586938858032227|-0.558689534664154|-0.43343061208724976",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0000001270416465",
				PosOffset = "0|0|0",
				Radius = "3.8741366863250732",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity51 = {
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
				Position = "-5.153940200805664|7.811143398284912|-12.436418533325195",
				Rotation = "false|0.44573134183883667|0.5489331483840942|-0.5489287376403809|-0.44572773575782776",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "3.8741366863250732",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity52 = {
	Name = "Spawner",
	Components = {
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-3.3911216259002686|4.0|-17.315317153930664",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "1.0|1.0|1.0"
			}
		},
		{
			Name = "SPAWNPOINT",
			Arguments = {
			}
		}
	}
}

Entity53 = {
	Name = "Spawner.003",
	Components = {
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "13.14560604095459|4.0|6.5709733963012695",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "1.0|1.0|1.0"
			}
		},
		{
			Name = "SPAWNPOINT",
			Arguments = {
			}
		}
	}
}

Entity54 = {
	Name = "Gun",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "pistol"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.8130000233650208|4.739999771118164|3.499999761581421",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|0.0",
				Scale = "0.30000001192092896|0.30000001192092896|0.30000001192092896"
			}
		},
		{
			Name = "ANIMATOR",
			Arguments = {
				AnimNames = "shootPistol|reloadPistol|idlePistol|reloadSpecialPistol",
				AnimMeshNames = "shootPistol|reloadPistol|idlePistol|reloadPistolEspecial",
				NextAnim = "idlePistol|idlePistol|idlePistol|idlePistol",
				LoopAnims = "false|false|true|false"
			}
		},
		{
			Name = "AUDIO_EMITTER",
			Arguments = {
				SongName = "pistolShoot.wav",
				Is3D = "false"
			}
		},
		{
			Name = "PARTICLE_EMITTER",
			Arguments = {
				Loop = "false",
				Time = "0.05",
				Started = "false",
				Name = "Muzzle"
			}
		},
		{
			Name = "WEAPON_COMPONENT",
			Arguments = {
				MaxAmmo = "50",
				MagazineSize = "25",
				Cadence = "0.25"
			}
		}
	}
}

Entity55 = {
	Name = "Shotgun",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "shotgun"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.8100000023841858|5.008554458618164|2.835289478302002",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|0.0",
				Scale = "0.10000000149011612|0.10000000149011612|0.10000000149011612"
			}
		},
		{
			Name = "ANIMATOR",
			Arguments = {
				AnimNames = "shootShotgun|reloadShotgun|idleShotgun",
				AnimMeshNames = "shootShotgun|reloadShotgun|idleShotgun",
				NextAnim = "idleShotgun|idleShotgun|idleShotgun",
				LoopAnims = "false|false|true"
			}
		},
		{
			Name = "AUDIO_EMITTER",
			Arguments = {
				SongName = "shotgunShoot.wav",
				Is3D = "false"
			}
		},
		{
			Name = "PARTICLE_EMITTER",
			Arguments = {
				Loop = "false",
				Time = "0.05",
				Started = "false",
				Name = "Muzzle"
			}
		},
		{
			Name = "SHOTGUN",
			Arguments = {
				MaxAmmo = "10",
				MagazineSize = "2",
				Cadence = "0.8",
				Balas = "3"
			}
		}
	}
}

Entity56 = {
	Name = "Player",
	Components = {
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.813310980796814|5.464509963989258|5.160520076751709",
				Rotation = "false|1.0|2.1855694143368964e-08|0.0|-0.0",
				Scale = "1.1050000190734863|1.1050000190734863|1.1050000190734863"
			}
		}
	}
}

Entity57 = {
	Name = "A_LIGHT.001",
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
				LightType = "LT_DIRECTIONAL",
				DiffuseColor = "0.5|0.5|0.5",
				SpecularColor = "0|0|0"
			}
		}
	}
}

Entity58 = {
	Name = "Rifle",
	Components = {
		{
			Name = "MESH_RENDERER",
			Arguments = {
				Mesh = "rifle"
			}
		},
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.8299999833106995|4.849999904632568|3.2099997997283936",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "0.30000001192092896|0.30000001192092896|0.30000001192092896"
			}
		},
		{
			Name = "ANIMATOR",
			Arguments = {
				AnimNames = "shootRifle|reloadRifle|idleRifle",
				AnimMeshNames = "fireRifle|reloadRifle|idleRifle",
				NextAnim = "idleRifle|idleRifle|idleRifle",
				LoopAnims = "false|false|true"
			}
		},
		{
			Name = "AUDIO_EMITTER",
			Arguments = {
				SongName = "rifleShoot.wav",
				Is3D = "false"
			}
		},
		{
			Name = "PARTICLE_EMITTER",
			Arguments = {
				Loop = "false",
				Time = "0.05",
				Started = "false",
				Name = "Muzzle"
			}
		},
		{
			Name = "RIFLE",
			Arguments = {
				MaxAmmo = "6",
				MagazineSize = "3",
				Cadence = "1",
				Damage = "50"
			}
		}
	}
}

Entity59 = {
	Name = "AUI_ROUND_TEXT",
	Components = {
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.6480690240859985|1.407318353652954|0.683670163154602",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "0.6571059823036194|0.6571059823036194|0.6571059823036194"
			}
		},
		{
			Name = "TEXT",
			Arguments = {
				OverlayName = "RoundText",
				XPos = "10",
				YPos = "83",
				Depth = "1",
				Tam = "12",
				Text = "XX",
				Font = "01-digit2000.regular.ttf",
				Color = "1|129|255"
			}
		}
	}
}

Entity60 = {
	Name = "AUI_HELMET_IMAGE",
	Components = {
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.6480690240859985|1.407318353652954|0.683670163154602",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "0.6571059823036194|0.6571059823036194|0.6571059823036194"
			}
		},
		{
			Name = "IMAGE",
			Arguments = {
				OverlayName = "HelmetImage",
				XPos = "50",
				YPos = "50",
				Width = "192",
				Height = "108",
				Texture = "Helmet.png",
				Depth = "1"
			}
		}
	}
}

Entity61 = {
	Name = "AUI_FRONTBAR",
	Components = {
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.6480690240859985|1.407318353652954|0.683670163154602",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "0.6571059823036194|0.6571059823036194|0.6571059823036194"
			}
		},
		{
			Name = "IMAGE",
			Arguments = {
				OverlayName = "FrontBarImage",
				XPos = "18",
				YPos = "24",
				Width = "22",
				Height = "7",
				Texture = "FrontBar.png",
				Depth = "3"
			}
		}
	}
}

Entity62 = {
	Name = "Spawner.002",
	Components = {
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-10.585010528564453|4.0|-8.098311424255371",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "1.0|1.0|1.0"
			}
		},
		{
			Name = "SPAWNPOINT",
			Arguments = {
			}
		}
	}
}

Entity63 = {
	Name = "Spawner.005",
	Components = {
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "4.984157562255859|4.0|-18.0639591217041",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "1.0|1.0|1.0"
			}
		},
		{
			Name = "SPAWNPOINT",
			Arguments = {
			}
		}
	}
}

Entity64 = {
	Name = "Spawner.006",
	Components = {
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "-8.778257369995117|3.999999761581421|14.095857620239258",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "1.0|1.0|1.0"
			}
		},
		{
			Name = "SPAWNPOINT",
			Arguments = {
			}
		}
	}
}

Entity65 = {
	Name = "healthEffect",
	Components = {
		{
			Name = "TRANSFORM",
			Arguments = {
				Position = "0.0|0.0|-0.0",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "1.0|1.0|1.0"
			}
		}
	}
}

Entity66 = {
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
				Position = "-11.428275108337402|4.949470520019531|-12.211581230163574",
				Rotation = "false|0.08575940877199173|-0.08575934916734695|-0.7018869519233704|-0.7018870115280151",
				Scale = "0.6109504699707031|0.6109504699707031|0.6109503507614136"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "3.1669190232084765|3.4935203217624586|3.1669190232084765",
				PosOffset = "0|0|0",
				Radius = "2.1343674659729004",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity67 = {
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
				Position = "-12.312234878540039|2.8465185165405273|-11.592554092407227",
				Rotation = "false|0.38649672269821167|-0.38649675250053406|0.5921319723129272|0.5921319723129272",
				Scale = "0.6109504103660583|0.6109504103660583|0.6109503507614136"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "3.1669193321747695|3.4935203217624586|3.1669193321747695",
				PosOffset = "0|0|0",
				Radius = "2.1343674659729004",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity68 = {
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
				Position = "-10.450996398925781|2.8465189933776855|-11.975370407104492",
				Rotation = "false|0.7066218852996826|-0.7066220641136169|0.026180341839790344|0.026180321350693703",
				Scale = "0.6109504103660583|0.6109504103660583|0.6109503507614136"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "3.1669189419326567|3.4935203217624586|3.1669189419326567",
				PosOffset = "0|0|0",
				Radius = "2.1343674659729004",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity69 = {
	Name = "Cube.010",
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
				Position = "10.225675582885742|2.9162464141845703|11.626740455627441",
				Rotation = "false|0.3603763282299042|-0.3603764772415161|0.6083821058273315|0.6083822250366211",
				Scale = "1.9370685815811157|0.9383481740951538|0.8470563292503357"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "3.8741371631622314",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity70 = {
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
				Position = "12.975065231323242|7.811143398284912|13.729307174682617",
				Rotation = "false|0.44573134183883667|0.5489331483840942|-0.5489287376403809|-0.44572773575782776",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "3.8741366863250732",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity71 = {
	Name = "Cube.025",
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
				Position = "13.088114738464355|4.00625467300415|13.320713996887207",
				Rotation = "false|0.18288034200668335|0.6830511689186096|-0.6830455660820007|-0.18287883698940277",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "3.8741366863250732",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity72 = {
	Name = "Cube.026",
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
				Position = "-12.312976837158203|4.006251335144043|9.665365219116211",
				Rotation = "false|0.43343400955200195|0.5586938858032227|-0.558689534664154|-0.43343061208724976",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0000001270416465",
				PosOffset = "0|0|0",
				Radius = "3.8741366863250732",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity73 = {
	Name = "Cube.027",
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
				Position = "6.728567123413086|4.006251335144043|16.076400756835938",
				Rotation = "false|0.43343400955200195|0.5586938858032227|-0.558689534664154|-0.43343061208724976",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0000001270416465",
				PosOffset = "0|0|0",
				Radius = "3.8741366863250732",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity74 = {
	Name = "Cube.028",
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
				Position = "-12.853012084960938|2.916250705718994|-5.1688008308410645",
				Rotation = "false|0.226474329829216|-0.2264743596315384|0.6698577404022217|0.6698577404022217",
				Scale = "1.9370683431625366|0.938348114490509|0.8470563292503357"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "1.999999876917828|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "3.874136447906494",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity75 = {
	Name = "Cube.029",
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
				Position = "-9.718517303466797|2.9162468910217285|-0.1500990390777588",
				Rotation = "false|0.3791821002960205|-0.3791821300983429|0.5968424677848816|0.5968424677848816",
				Scale = "1.9370685815811157|0.9383481740951538|0.8470563292503357"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|1.9999998729583615",
				PosOffset = "0|0|0",
				Radius = "3.8741371631622314",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity76 = {
	Name = "Cube.030",
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
				Position = "-8.921632766723633|2.9162468910217285|3.7394800186157227",
				Rotation = "false|0.5132172703742981|-0.5132173299789429|0.48642370104789734|0.48642370104789734",
				Scale = "1.9370685815811157|0.9383481740951538|0.8470563292503357"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|1.9999998729583615",
				PosOffset = "0|0|0",
				Radius = "3.8741371631622314",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity77 = {
	Name = "Cube.031",
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
				Position = "-10.159234046936035|2.9162468910217285|7.502069473266602",
				Rotation = "false|0.604570746421814|-0.6045708060264587|0.36673447489738464|0.36673447489738464",
				Scale = "1.9370685815811157|0.9383481740951538|0.8470563292503357"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "3.8741371631622314",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "DEFAULT",
				Trigger = "false"
			}
		}
	}
}

Entity78 = {
	Name = "Floor.003",
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
				Position = "0.8228198289871216|1.7865326404571533|37.782833099365234",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "15.294673919677734|18.7946720123291|0.28266042470932007"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "37.5893440246582",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "FLOOR",
				Trigger = "false"
			}
		}
	}
}

Entity79 = {
	Name = "Floor.004",
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
				Position = "0.8228198289871216|1.7865326404571533|-35.660037994384766",
				Rotation = "false|0.7071067094802856|-0.7071068286895752|0.0|-0.0",
				Scale = "15.294673919677734|18.7946720123291|0.28266042470932007"
			}
		},
		{
			Name = "RIGIDBODY",
			Arguments = {
				Mass = "1",
				Bounciness = "0",
				Friction = "1",
				AABB = "2.0|2.0|2.0",
				PosOffset = "0|0|0",
				Radius = "37.5893440246582",
				Shape = "BOX",
				CollisionFlag = "STATIC",
				CollisionLayer = "FLOOR",
				Trigger = "false"
			}
		}
	}
}

Entities = { Entity1, Entity2, Entity3, Entity4, Entity5, Entity6, Entity7, Entity8, Entity9, Entity10, Entity11, Entity12, Entity13, Entity14, Entity15, Entity16, Entity17, Entity18, Entity19, Entity20, Entity21, Entity22, Entity23, Entity24, Entity25, Entity26, Entity27, Entity28, Entity29, Entity30, Entity31, Entity32, Entity33, Entity34, Entity35, Entity36, Entity37, Entity38, Entity39, Entity40, Entity41, Entity42, Entity43, Entity44, Entity45, Entity46, Entity47, Entity48, Entity49, Entity50, Entity51, Entity52, Entity53, Entity54, Entity55, Entity56, Entity57, Entity58, Entity59, Entity60, Entity61, Entity62, Entity63, Entity64, Entity65, Entity66, Entity67, Entity68, Entity69, Entity70, Entity71, Entity72, Entity73, Entity74, Entity75, Entity76, Entity77, Entity78, Entity79 }

CollisionLayers = {
	Layers = {
		DEFAULT = "",
		FLOOR = "",
		BOT = "BOT|PLAYER",
		PLAYER = "BOT"
	}
}