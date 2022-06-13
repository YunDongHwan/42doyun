import { Controller, Get, Param, Post, Body, Put, Delete } from '@nestjs/common';
import bodyParser = require('body-parser');
import { CreateCat } from './CreateCatDto';
import { CatsService } from './cats.service';
import { Cats } from './interface/cats.interface';

@Controller('cats')
export class CatsController {
    //private를 해야 선언과 초기화가 동시에 됨
    constructor(private catsService: CatsService) { };
    @Get()
    findAll(): Cats[] {
        return this.catsService.findAll();
    }

    @Get(':id')
    fineOne(@Param('id') id: string): string {
        return `This action returns a #${id} cat`;
    }

    @Post()
    create(@Body() createCatDto: CreateCatDto) { //CreateCatDto class 형식으로 body parameter를 맏는다
        return this.catsService.create(createCatDto);
    }

    @Put('id')
    update(@Param('id') id: string, @Body() createCatDto: CreateCatDto) {
        return `This action updates a #${id} cat`;
    }

    @Delete(':id')
    remove(@Param('id') id: string) {
        return `This action removes a #${id} cat`;
    }
}
