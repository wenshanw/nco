/* $ANTLR 2.7.7 (20130428): "ncoGrammer.g" -> "ncoTree.cpp"$ */
#include "ncoTree.hpp"
#include <antlr/Token.hpp>
#include <antlr/AST.hpp>
#include <antlr/NoViableAltException.hpp>
#include <antlr/MismatchedTokenException.hpp>
#include <antlr/SemanticException.hpp>
#include <antlr/BitSet.hpp>
#line 1 "ncoGrammer.g"
#line 11 "ncoTree.cpp"
ncoTree::ncoTree()
	: ANTLR_USE_NAMESPACE(antlr)TreeParser() {
}

int  ncoTree::lmt_peek(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
#line 1071 "ncoGrammer.g"
	int nbr_dmn=0;
#line 19 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST lmt_peek_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST lmt = ANTLR_USE_NAMESPACE(antlr)nullAST;
	
	try {      // for error handling
		lmt = _t;
		match(_t,LMT_LIST);
		_t = _t->getNextSibling();
		if ( inputState->guessing==0 ) {
#line 1073 "ncoGrammer.g"
			
			RefAST aRef;     
			aRef=lmt->getFirstChild();
			nbr_dmn=0;
			while(aRef) {
			if(aRef->getType() == LMT) nbr_dmn++;    
			aRef=aRef->getNextSibling();     
			}   
			
#line 38 "ncoTree.cpp"
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return nbr_dmn;
}

int  ncoTree::statements(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
#line 1084 "ncoGrammer.g"
	int iret=0;
#line 57 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST statements_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST blk = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST exp = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST ass = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST fss = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST stmt = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST stmt3 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST lgcl = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST stmt1 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST e1 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST e2 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST e3 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST stmt2 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST dtyp = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST def = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST pvid = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST patt = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST pstr = ANTLR_USE_NAMESPACE(antlr)nullAST;
#line 1084 "ncoGrammer.g"
	
	var_sct *var=NULL;
	var_sct *var2=NULL;
	const std::string fnc_nm("statements");
	// list of while/for loops entered n.b depth is lpp_vtr.size()
	// Temporary fix so call run_exe only does a single parse in the
	// nested block
	static std::vector<std::string> lpp_vtr;
	
#line 86 "ncoTree.cpp"
	
	try {      // for error handling
		if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = ASTNULL;
		switch ( _t->getType()) {
		case BLOCK:
		{
			blk = _t;
			match(_t,BLOCK);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1094 "ncoGrammer.g"
				
				//std::cout <<"Num of Children in block="<<blk->getNumberOfChildren()<<endl;
				iret=run_exe(blk->getFirstChild(),lpp_vtr.size() );
				
				
#line 104 "ncoTree.cpp"
			}
			break;
		}
		case EXPR:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t221 = _t;
			exp = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
			match(_t,EXPR);
			_t = _t->getFirstChild();
			ass = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			_t = __t221;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1100 "ncoGrammer.g"
				
				RefAST tr;
				RefAST ntr;  
				
				if(ass->getType()==ASSIGN && prs_arg->ntl_scn ){
				ntr=ass->getFirstChild();
				if(ntr->getType()==UTIMES) 
				ntr=ntr->getFirstChild();
				
				if(ntr->getType() == VAR_ID || ntr->getType() ==ATT_ID){
				ntr->addChild( astFactory->create(NORET,"no_ret") );
				// std::cout << "Modified assign "<<exp->toStringTree()<<std::endl;      
				}
				} 
				
				var=out(exp->getFirstChild());
				if(var != (var_sct*)NULL)
				var=nco_var_free(var);
				iret=EXPR;
				
#line 141 "ncoTree.cpp"
			}
			break;
		}
		case FEXPR:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t222 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp118_AST_in = _t;
			match(_t,FEXPR);
			_t = _t->getFirstChild();
			fss = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			_t = __t222;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1124 "ncoGrammer.g"
				
				
				var=out(fss);
				if(var != (var_sct*)NULL)
				var=nco_var_free(var);
				iret=FEXPR;
				
#line 165 "ncoTree.cpp"
			}
			break;
		}
		case IF:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t223 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp119_AST_in = _t;
			match(_t,IF);
			_t = _t->getFirstChild();
			var=out(_t);
			_t = _retTree;
			stmt = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			_t = __t223;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1132 "ncoGrammer.g"
				
				//if can have only 3 or 4 parts  , 1 node and 2 or 3 siblings
				// IF LOGICAL_EXP STATEMENT1 STATEMENT2
				bool br;
					  //Calculate logical expression
					  br=ncap_var_lgcl(var);
					  var=nco_var_free(var);
				
				if(br){ 
				// Execute 2nd sibling  
				if(stmt->getType()==BLOCK ) {
				if(stmt->getFirstChild()) 
				iret=run_exe(stmt->getFirstChild(),lpp_vtr.size());
				}else
				iret=statements(stmt);     
				}
				
				// See if else stmt exists (3rd sibling)       
					  if(!br && (stmt=stmt->getNextSibling()) ){
				if(stmt->getType()==BLOCK ){
				if(stmt->getFirstChild()) 
				iret=run_exe(stmt->getFirstChild(),lpp_vtr.size());
				}else
				iret=statements(stmt);     
				}
				
				var=NULL_CEWI;
				
				
#line 213 "ncoTree.cpp"
			}
			break;
		}
		case WHERE:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t224 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp120_AST_in = _t;
			match(_t,WHERE);
			_t = _t->getFirstChild();
			var=out(_t);
			_t = _retTree;
			stmt3 = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			_t = __t224;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1162 "ncoGrammer.g"
				
				// convert mask to short 
				RefAST tr; 
				var=nco_var_cnf_typ(NC_SHORT,var);
				
				//change missing values to zero
				if(var->has_mss_val){
				var=ncap_var_var_stc(var,NULL_CEWI,MISS2ZERO);
				var->has_mss_val=False;
				var->mss_val.vp=(void*)nco_free(var->mss_val.vp);
				}         
				
				//deal with block
				if(stmt3->getType()==BLOCK){
				tr=stmt3->getFirstChild();
				while(tr) {
				(void)where_assign(tr,var);       
				tr=tr->getNextSibling();
				} 
				} else 
				where_assign(stmt3,var);
				
				// deal with else-where
				if(tr=stmt3->getNextSibling()) {
				
				//invert mask
				var=ncap_var_var_stc(var,NULL_CEWI,LNOT); 
				
				if(tr->getType()==BLOCK){
				tr=tr->getFirstChild();
				while(tr) {
				(void)where_assign(tr,var);       
				tr=tr->getNextSibling();
				} 
				} else 
				where_assign(tr,var);
				
				}
				
				if(var != (var_sct*)NULL)
				var=nco_var_free(var);
				iret=WHERE;      
				
#line 275 "ncoTree.cpp"
			}
			break;
		}
		case WHILE:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t225 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp121_AST_in = _t;
			match(_t,WHILE);
			_t = _t->getFirstChild();
			lgcl = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			stmt1 = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			_t = __t225;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1206 "ncoGrammer.g"
				
				
				bool br;
				var_sct *var_tf;  
				
				var_tf=out(lgcl);
				br=ncap_var_lgcl(var_tf);
				var_tf=nco_var_free(var_tf);
				
				lpp_vtr.push_back("while");
				
				while(br){ 
				if(stmt1->getType()==BLOCK)
				iret=run_exe(stmt1,lpp_vtr.size());
				else
				iret=statements(stmt1);     
				
				if(iret==BREAK) break;
				var_tf=out(lgcl);
				br=ncap_var_lgcl(var_tf); 
				var_tf=nco_var_free(var_tf);       
				
				}
				lpp_vtr.pop_back(); 
				iret=WHILE;
				var=NULL_CEWI; 
				
				
#line 323 "ncoTree.cpp"
			}
			break;
		}
		case FOR:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t226 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp122_AST_in = _t;
			match(_t,FOR);
			_t = _t->getFirstChild();
			e1 = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			e2 = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			e3 = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			stmt2 = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			_t = __t226;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1235 "ncoGrammer.g"
				
				bool b1,b2,b3,br;
				var_sct *var_f1;
				var_sct *var_f2;
				var_sct *var_f3;
				
				b1=(e1->getType()!=NULL_NODE ? true:false);
				b2=(e2->getType()!=NULL_NODE ? true:false);
				b3=(e3->getType()!=NULL_NODE ? true:false);
				
				lpp_vtr.push_back("for");
				
				if(b1){
				var_f1=out(e1);
				var_f1=nco_var_free(var_f1);
				}          
				
				if(b2){
				var_f2=out(e2);
				br=ncap_var_lgcl(var_f2);
				var_f2=nco_var_free(var_f2);
				} else br=true;
				
				while(br){
				
				if(stmt2->getType()==BLOCK)
				iret=run_exe(stmt2,lpp_vtr.size());
				else
				iret=statements(stmt2);     
				
				if(iret==BREAK) break;
				
				if(b3){
				var_f3=out(e3);
				var_f3=nco_var_free(var_f3);
				}
				
				if(b2){
				var_f2=out(e2);
				br=ncap_var_lgcl(var_f2);
				var_f2=nco_var_free(var_f2);
				} 
				
				} // end while
				
				lpp_vtr.pop_back();
				iret=FOR;
				var=NULL_CEWI;                
				
				
#line 399 "ncoTree.cpp"
			}
			break;
		}
		case ELSE:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp123_AST_in = _t;
			match(_t,ELSE);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1286 "ncoGrammer.g"
				iret=ELSE;
#line 411 "ncoTree.cpp"
			}
			break;
		}
		case BREAK:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp124_AST_in = _t;
			match(_t,BREAK);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1287 "ncoGrammer.g"
				iret=BREAK;
#line 423 "ncoTree.cpp"
			}
			break;
		}
		case CONTINUE:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp125_AST_in = _t;
			match(_t,CONTINUE);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1288 "ncoGrammer.g"
				iret=CONTINUE;
#line 435 "ncoTree.cpp"
			}
			break;
		}
		case NULL_NODE:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp126_AST_in = _t;
			match(_t,NULL_NODE);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1289 "ncoGrammer.g"
				iret=NULL_NODE;
#line 447 "ncoTree.cpp"
			}
			break;
		}
		case DEFDIM:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t227 = _t;
			dtyp = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
			match(_t,DEFDIM);
			_t = _t->getFirstChild();
			def = _t;
			match(_t,NSTRING);
			_t = _t->getNextSibling();
			var=out(_t);
			_t = _retTree;
			{
			if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = ASTNULL;
			switch ( _t->getType()) {
			case VALUE_LIST:
			case POST_INC:
			case POST_DEC:
			case UTIMES:
			case WHERE_ASSIGN:
			case NSTRING:
			case VAR_ID:
			case ATT_ID:
			case DIVIDE:
			case DOT:
			case FUNC:
			case INC:
			case DEC:
			case LNOT:
			case PLUS:
			case MINUS:
			case TIMES:
			case CARET:
			case MOD:
			case FLTHAN:
			case FGTHAN:
			case LTHAN:
			case GTHAN:
			case GEQ:
			case LEQ:
			case EQ:
			case NEQ:
			case LAND:
			case LOR:
			case QUESTION:
			case ASSIGN:
			case PLUS_ASSIGN:
			case MINUS_ASSIGN:
			case TIMES_ASSIGN:
			case DIVIDE_ASSIGN:
			case NCAP_FLOAT:
			case NCAP_DOUBLE:
			case NCAP_INT:
			case NCAP_BYTE:
			case NCAP_UBYTE:
			case NCAP_SHORT:
			case NCAP_USHORT:
			case NCAP_UINT:
			case NCAP_INT64:
			case NCAP_UINT64:
			case N4STRING:
			case DIM_ID_SIZE:
			{
				var2=out(_t);
				_t = _retTree;
				break;
			}
			case 3:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(_t);
			}
			}
			}
			_t = __t227;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1291 "ncoGrammer.g"
				
				
				bool bunlimited=false;      
				int ityp;  
				int dCall;  
				long sz;
				
				// 0 - specific - UNLIMITED    
				// 1 - regular LIMITED or UNLIMITED
				dCall=atoi(dtyp->getText().c_str());    
				iret=DEFDIM;
				
				var=nco_var_cnf_typ((nc_type)NC_INT64,var);
				(void)cast_void_nctype((nc_type)NC_INT64,&var->val);
				sz=var->val.i64p[0];
				var=(var_sct*)nco_var_free(var);
				
				if( dCall==0 ){ 
				bunlimited =true;
				} else    
				if(dCall==1 && var2){
				int ityp;
				// nb var2 is in upper scope - defined at statment action start
				var2=nco_var_cnf_typ(NC_INT,var2);
				(void)cast_void_nctype(NC_INT,&var2->val);
				ityp=var2->val.ip[0]; 
				(void)cast_nctype_void(NC_INT,&var2->val);
				var2=nco_var_free(var2);
				
				if( ityp==0)
				bunlimited=true;
				else if( ityp==1 )  
				bunlimited=false;
				else    
				err_prn(fnc_nm,"defdim for "+ def->getText() + ". Third argument must be 0 for \"UNLIMITED\" or 1 for \"LIMITED\" or void"); 
				
				} 
				
				(void)ncap_def_dim(def->getText(),sz,bunlimited,prs_arg);
				
#line 572 "ncoTree.cpp"
			}
			break;
		}
		default:
			bool synPredMatched231 = false;
			if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = ASTNULL;
			if (((_t->getType() == PRINT))) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t231 = _t;
				synPredMatched231 = true;
				inputState->guessing++;
				try {
					{
					ANTLR_USE_NAMESPACE(antlr)RefAST __t230 = _t;
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp127_AST_in = _t;
					match(_t,PRINT);
					_t = _t->getFirstChild();
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp128_AST_in = _t;
					match(_t,VAR_ID);
					_t = _t->getNextSibling();
					_t = __t230;
					_t = _t->getNextSibling();
					}
				}
				catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
					synPredMatched231 = false;
				}
				_t = __t231;
				inputState->guessing--;
			}
			if ( synPredMatched231 ) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t232 = _t;
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp129_AST_in = _t;
				match(_t,PRINT);
				_t = _t->getFirstChild();
				pvid = _t;
				match(_t,VAR_ID);
				_t = _t->getNextSibling();
				_t = __t232;
				_t = _t->getNextSibling();
				if ( inputState->guessing==0 ) {
#line 1333 "ncoGrammer.g"
					
					
					int var_id;
					int fl_id=-1;
					char *fmt_sng;
					
					std::string va_nm(pvid->getText());
					NcapVar *Nvar;
					
					if(prs_arg->ntl_scn) goto end2;
					Nvar=prs_arg->var_vtr.find(va_nm);
					
					if(Nvar && Nvar->flg_mem){   
					wrn_prn(fnc_nm,"Cannot print out RAM variables at the moment!");
					goto end2;
					}
					
					// check output first -nb can only print out vars that are defined AND written
					// it is possible to get with the var defined in output but no data
					// flg_stt==1 mean var defined but no data !!
					// So we try to use var in input -if it exist their    
					if(Nvar && Nvar->flg_stt==2){
					fl_id=prs_arg->out_id;   
					}else{
					// Check input file for var   
					if(NC_NOERR==nco_inq_varid_flg(prs_arg->in_id,va_nm.c_str(),&var_id))
					fl_id=prs_arg->in_id;
					}
					
					if(fl_id==-1) {
					wrn_prn(fnc_nm,"Print function cannot find var \""+va_nm+"\" in input or output");
					goto end2;
					}
					
					// Grab format string 
					if(pvid->getNextSibling() && pvid->getNextSibling()->getType()==NSTRING)
					fmt_sng=strdup(pvid->getNextSibling()->getText().c_str());
					else 
					fmt_sng=(char*)NULL; 
					
					if( fl_id >=0)
					(void)nco_prn_var_val_lmt(fl_id,va_nm.c_str(),(lmt_sct*)NULL,0L,fmt_sng,prs_arg->FORTRAN_IDX_CNV,False,False);
					
					if(fmt_sng) fmt_sng=(char*)nco_free(fmt_sng); 
					
					end2: ;
					
#line 662 "ncoTree.cpp"
				}
			}
			else {
				bool synPredMatched235 = false;
				if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
					_t = ASTNULL;
				if (((_t->getType() == PRINT))) {
					ANTLR_USE_NAMESPACE(antlr)RefAST __t235 = _t;
					synPredMatched235 = true;
					inputState->guessing++;
					try {
						{
						ANTLR_USE_NAMESPACE(antlr)RefAST __t234 = _t;
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp130_AST_in = _t;
						match(_t,PRINT);
						_t = _t->getFirstChild();
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp131_AST_in = _t;
						match(_t,ATT_ID);
						_t = _t->getNextSibling();
						_t = __t234;
						_t = _t->getNextSibling();
						}
					}
					catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
						synPredMatched235 = false;
					}
					_t = __t235;
					inputState->guessing--;
				}
				if ( synPredMatched235 ) {
					ANTLR_USE_NAMESPACE(antlr)RefAST __t236 = _t;
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp132_AST_in = _t;
					match(_t,PRINT);
					_t = _t->getFirstChild();
					patt = _t;
					match(_t,ATT_ID);
					_t = _t->getNextSibling();
					_t = __t236;
					_t = _t->getNextSibling();
					if ( inputState->guessing==0 ) {
#line 1380 "ncoGrammer.g"
						
						
						int apsn;
						var_sct *var1;
						char *fmt_sng;
						std::string fl_nm;
						std::string att_nm;
						std::string var_nm;
						NcapVar *Nvar;
						
						var=NULL_CEWI;
						
						// print only on second parse
						if(prs_arg->ntl_scn) goto end3;
						
						fl_nm=patt->getText();
						apsn=fl_nm.find("@");
						var_nm=fl_nm.substr(0,apsn);
						att_nm=fl_nm.substr(apsn+1);            
						
						Nvar=prs_arg->var_vtr.find(var_nm);
						if( Nvar && att_nm==std::string(nco_mss_val_sng_get()) ){         
						if(Nvar->var->has_mss_val==True){
						var1=ncap_sclr_var_mk(fl_nm,Nvar->var->type,true);
						(void)memcpy(var1->val.vp,Nvar->var->mss_val.vp, nco_typ_lng(Nvar->var->type));
						var=var1;
						}else{
						wrn_prn(fnc_nm,"Cannot print missing value \""+ fl_nm+ "\" for variable \""+ var_nm +"\" as it is undefined");
						goto end3;    
						}
						}else{   
						Nvar=prs_arg->var_vtr.find(fl_nm);
						if(Nvar==NULL_CEWI) 
						var=ncap_att_init(fl_nm,prs_arg);
						else
						var=nco_var_dpl(Nvar->var); 
						}
						
						if(var==NULL_CEWI ){
						wrn_prn(fnc_nm,"Cannot print  attribute \"" +fl_nm+ "\". Not present in input or output files.");
						goto end3;    
						}
						
						// Grab format string 
						if(patt->getNextSibling() && patt->getNextSibling()->getType()==NSTRING)
						fmt_sng=strdup(patt->getNextSibling()->getText().c_str());
						else 
						fmt_sng=(char*)NULL; 
						
						(void)ncap_att_prn(var,fmt_sng);
						var=nco_var_free(var); 
						
						end3:   ;
						
#line 758 "ncoTree.cpp"
					}
				}
				else {
					bool synPredMatched239 = false;
					if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
						_t = ASTNULL;
					if (((_t->getType() == PRINT))) {
						ANTLR_USE_NAMESPACE(antlr)RefAST __t239 = _t;
						synPredMatched239 = true;
						inputState->guessing++;
						try {
							{
							ANTLR_USE_NAMESPACE(antlr)RefAST __t238 = _t;
							ANTLR_USE_NAMESPACE(antlr)RefAST tmp133_AST_in = _t;
							match(_t,PRINT);
							_t = _t->getFirstChild();
							ANTLR_USE_NAMESPACE(antlr)RefAST tmp134_AST_in = _t;
							match(_t,NSTRING);
							_t = _t->getNextSibling();
							_t = __t238;
							_t = _t->getNextSibling();
							}
						}
						catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
							synPredMatched239 = false;
						}
						_t = __t239;
						inputState->guessing--;
					}
					if ( synPredMatched239 ) {
						ANTLR_USE_NAMESPACE(antlr)RefAST __t240 = _t;
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp135_AST_in = _t;
						match(_t,PRINT);
						_t = _t->getFirstChild();
						pstr = _t;
						match(_t,NSTRING);
						_t = _t->getNextSibling();
						_t = __t240;
						_t = _t->getNextSibling();
						if ( inputState->guessing==0 ) {
#line 1435 "ncoGrammer.g"
							
							char *prn_sng;
							
							if(!prs_arg->ntl_scn){
							prn_sng=strdup(pstr->getText().c_str());
							(void)sng_ascii_trn(prn_sng);            
							
							fprintf(stdout,"%s",prn_sng);
							prn_sng=(char*)nco_free(prn_sng);
							}    
							
#line 811 "ncoTree.cpp"
						}
					}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(_t);
		}
		}}}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return iret;
}

var_sct * ncoTree::out(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
#line 1989 "ncoGrammer.g"
	var_sct *var;
#line 835 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST out_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST pls_asn = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST min_asn = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST tim_asn = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST div_asn = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST asn = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST wasn = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST qus = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST m = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST args = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST mtd = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST mfnc = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST margs = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST dval = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST lmt = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST v = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST att = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST vlst = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST str = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST str1 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST val_float = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST val_double = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST val_int = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST val_short = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST val_byte = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST val_ubyte = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST val_ushort = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST val_uint = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST val_int64 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST val_uint64 = ANTLR_USE_NAMESPACE(antlr)nullAST;
#line 1989 "ncoGrammer.g"
	
	const std::string fnc_nm("out"); 
		var_sct *var1;
	var_sct *var2;
	var=NULL_CEWI;
	
#line 874 "ncoTree.cpp"
	
	try {      // for error handling
		if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = ASTNULL;
		switch ( _t->getType()) {
		case TIMES:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t308 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp136_AST_in = _t;
			match(_t,TIMES);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t308;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2016 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, TIMES );
#line 895 "ncoTree.cpp"
			}
			break;
		}
		case DIVIDE:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t309 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp137_AST_in = _t;
			match(_t,DIVIDE);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t309;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2019 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, DIVIDE );
#line 914 "ncoTree.cpp"
			}
			break;
		}
		case MOD:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t310 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp138_AST_in = _t;
			match(_t,MOD);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t310;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2021 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, MOD);
#line 933 "ncoTree.cpp"
			}
			break;
		}
		case CARET:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t311 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp139_AST_in = _t;
			match(_t,CARET);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t311;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2023 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, CARET);
#line 952 "ncoTree.cpp"
			}
			break;
		}
		case LNOT:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t312 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp140_AST_in = _t;
			match(_t,LNOT);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			_t = __t312;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2026 "ncoGrammer.g"
				var=ncap_var_var_op(var1,NULL_CEWI, LNOT );
#line 969 "ncoTree.cpp"
			}
			break;
		}
		case INC:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t315 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp141_AST_in = _t;
			match(_t,INC);
			_t = _t->getFirstChild();
			var1=out_asn(_t);
			_t = _retTree;
			_t = __t315;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2032 "ncoGrammer.g"
				var=ncap_var_var_inc(var1,NULL_CEWI,INC,false,prs_arg);
#line 986 "ncoTree.cpp"
			}
			break;
		}
		case DEC:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t316 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp142_AST_in = _t;
			match(_t,DEC);
			_t = _t->getFirstChild();
			var1=out_asn(_t);
			_t = _retTree;
			_t = __t316;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2034 "ncoGrammer.g"
				var=ncap_var_var_inc(var1,NULL_CEWI, DEC,false,prs_arg );
#line 1003 "ncoTree.cpp"
			}
			break;
		}
		case POST_INC:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t317 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp143_AST_in = _t;
			match(_t,POST_INC);
			_t = _t->getFirstChild();
			var1=out_asn(_t);
			_t = _retTree;
			_t = __t317;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2036 "ncoGrammer.g"
				
				var=ncap_var_var_inc(var1,NULL_CEWI,POST_INC,false,prs_arg);
				
#line 1022 "ncoTree.cpp"
			}
			break;
		}
		case POST_DEC:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t318 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp144_AST_in = _t;
			match(_t,POST_DEC);
			_t = _t->getFirstChild();
			var1=out_asn(_t);
			_t = _retTree;
			_t = __t318;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2039 "ncoGrammer.g"
				
				var=ncap_var_var_inc(var1,NULL_CEWI,POST_DEC,false,prs_arg);
				
#line 1041 "ncoTree.cpp"
			}
			break;
		}
		case LAND:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t319 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp145_AST_in = _t;
			match(_t,LAND);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t319;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2044 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, LAND );
#line 1060 "ncoTree.cpp"
			}
			break;
		}
		case LOR:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t320 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp146_AST_in = _t;
			match(_t,LOR);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t320;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2046 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, LOR );
#line 1079 "ncoTree.cpp"
			}
			break;
		}
		case LTHAN:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t321 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp147_AST_in = _t;
			match(_t,LTHAN);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t321;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2049 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, LTHAN );
#line 1098 "ncoTree.cpp"
			}
			break;
		}
		case GTHAN:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t322 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp148_AST_in = _t;
			match(_t,GTHAN);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t322;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2051 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, GTHAN );
#line 1117 "ncoTree.cpp"
			}
			break;
		}
		case GEQ:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t323 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp149_AST_in = _t;
			match(_t,GEQ);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t323;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2053 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, GEQ );
#line 1136 "ncoTree.cpp"
			}
			break;
		}
		case LEQ:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t324 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp150_AST_in = _t;
			match(_t,LEQ);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t324;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2055 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, LEQ );
#line 1155 "ncoTree.cpp"
			}
			break;
		}
		case EQ:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t325 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp151_AST_in = _t;
			match(_t,EQ);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t325;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2057 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, EQ );
#line 1174 "ncoTree.cpp"
			}
			break;
		}
		case NEQ:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t326 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp152_AST_in = _t;
			match(_t,NEQ);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t326;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2059 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, NEQ );
#line 1193 "ncoTree.cpp"
			}
			break;
		}
		case FLTHAN:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t327 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp153_AST_in = _t;
			match(_t,FLTHAN);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t327;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2062 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, FLTHAN );
#line 1212 "ncoTree.cpp"
			}
			break;
		}
		case FGTHAN:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t328 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp154_AST_in = _t;
			match(_t,FGTHAN);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			var2=out(_t);
			_t = _retTree;
			_t = __t328;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2064 "ncoGrammer.g"
				var=ncap_var_var_op(var1,var2, FGTHAN );
#line 1231 "ncoTree.cpp"
			}
			break;
		}
		case PLUS_ASSIGN:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t329 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp155_AST_in = _t;
			match(_t,PLUS_ASSIGN);
			_t = _t->getFirstChild();
			pls_asn = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			var2=out(_t);
			_t = _retTree;
			_t = __t329;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2066 "ncoGrammer.g"
				
				var1=out_asn(pls_asn);
				var=ncap_var_var_inc(var1,var2, PLUS_ASSIGN ,(pls_asn->getType()==UTIMES), prs_arg);
				
#line 1254 "ncoTree.cpp"
			}
			break;
		}
		case MINUS_ASSIGN:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t330 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp156_AST_in = _t;
			match(_t,MINUS_ASSIGN);
			_t = _t->getFirstChild();
			min_asn = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			var2=out(_t);
			_t = _retTree;
			_t = __t330;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2070 "ncoGrammer.g"
				
				var1=out_asn(min_asn);
				var=ncap_var_var_inc(var1,var2, MINUS_ASSIGN ,(min_asn->getType()==UTIMES), prs_arg);
				
#line 1277 "ncoTree.cpp"
			}
			break;
		}
		case TIMES_ASSIGN:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t331 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp157_AST_in = _t;
			match(_t,TIMES_ASSIGN);
			_t = _t->getFirstChild();
			tim_asn = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			var2=out(_t);
			_t = _retTree;
			_t = __t331;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2074 "ncoGrammer.g"
				
				var1=out_asn(tim_asn);
				var=ncap_var_var_inc(var1,var2, TIMES_ASSIGN ,(tim_asn->getType()==UTIMES), prs_arg);
				
#line 1300 "ncoTree.cpp"
			}
			break;
		}
		case DIVIDE_ASSIGN:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t332 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp158_AST_in = _t;
			match(_t,DIVIDE_ASSIGN);
			_t = _t->getFirstChild();
			div_asn = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			var2=out(_t);
			_t = _retTree;
			_t = __t332;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2078 "ncoGrammer.g"
					
				var1=out_asn(div_asn);
				var=ncap_var_var_inc(var1,var2, DIVIDE_ASSIGN ,(div_asn->getType()==UTIMES), prs_arg);
				
#line 1323 "ncoTree.cpp"
			}
			break;
		}
		case ASSIGN:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t333 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp159_AST_in = _t;
			match(_t,ASSIGN);
			_t = _t->getFirstChild();
			asn = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			_t = __t333;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2084 "ncoGrammer.g"
				
				// Check for RAM variable - if present 
				// change tree - for example from:
				//     ( EXPR ( = ( * n1 ) ( + four four ) ) )
				// to  ( EXPR ( = n1 ( + four four ) ) )
				RefAST tr;
				bool bram;
				NcapVar *Nvar;
				
				if(asn->getType()==UTIMES){
				tr=asn->getFirstChild();
				tr->setNextSibling(asn->getNextSibling());
				bram=true;
				} else { 
				tr=asn; 
				bram=false;
				}
				
				// Die if attempting to create a RAM var 
				// from an existing disk var   
				Nvar= prs_arg->var_vtr.find(tr->getText());
				
				if(bram && tr->getType()==VAR_ID && Nvar && Nvar->flg_mem==false){
				std::string serr;
				serr= "It is impossible to recast disk variable: \"" + tr->getText() +"\" as a RAM variable.";
				err_prn(fnc_nm,serr );       
				}                
				
				if(prs_arg->ntl_scn)
				var=assign_ntl(tr,bram); 
				else
				var=assign(tr,bram);
				
				
#line 1374 "ncoTree.cpp"
			}
			break;
		}
		case WHERE_ASSIGN:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t334 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp160_AST_in = _t;
			match(_t,WHERE_ASSIGN);
			_t = _t->getFirstChild();
			wasn = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			_t = __t334;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2118 "ncoGrammer.g"
				
				
				
#line 1394 "ncoTree.cpp"
			}
			break;
		}
		case QUESTION:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t335 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp161_AST_in = _t;
			match(_t,QUESTION);
			_t = _t->getFirstChild();
			var1=out(_t);
			_t = _retTree;
			qus = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			_t = __t335;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2123 "ncoGrammer.g"
				
				bool br;
				
				// if initial scan 
				if(prs_arg->ntl_scn){
				var=ncap_var_udf("~question"); 
				} else {
				
				br=ncap_var_lgcl(var1);
				if(br) 
				var=out(qus);
				else
				var=out(qus->getNextSibling());      
				}   
				var1=nco_var_free(var1);
				
#line 1429 "ncoTree.cpp"
			}
			break;
		}
		case FUNC:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t336 = _t;
			m = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
			match(_t,FUNC);
			_t = _t->getFirstChild();
			args = _t;
			match(_t,FUNC_ARG);
			_t = _t->getNextSibling();
			_t = __t336;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2141 "ncoGrammer.g"
				
				// The lexer has appended the index of the function to the function name m - (name#index)
				//  the index is into fmc_vtr  
				string sm(m->getText()); 
				string sdx(sm,sm.find("#")+1,sm.length()-1) ;
				int idx=atoi(sdx.c_str());
				RefAST tr;  
				var=prs_arg->fmc_vtr[idx].vfnc()->fnd(tr ,args, prs_arg->fmc_vtr[idx],*this); 
				
#line 1455 "ncoTree.cpp"
			}
			break;
		}
		case DOT:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t337 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp162_AST_in = _t;
			match(_t,DOT);
			_t = _t->getFirstChild();
			mtd = _t;
			if ( _t == ANTLR_USE_NAMESPACE(antlr)nullAST ) throw ANTLR_USE_NAMESPACE(antlr)MismatchedTokenException();
			_t = _t->getNextSibling();
			mfnc = _t;
			match(_t,FUNC);
			_t = _t->getNextSibling();
			margs = _t;
			match(_t,FUNC_ARG);
			_t = _t->getNextSibling();
			_t = __t337;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2152 "ncoGrammer.g"
				
				// The lexer has appended the index of the function to the function name m - (name#index)
				//  the index is into fmc_vtr  
				string sm(mfnc->getText()); 
				string sdx(sm,sm.find("#")+1,sm.length()-1) ;
				int idx=atoi(sdx.c_str());
				var=prs_arg->fmc_vtr[idx].vfnc()->fnd(mtd ,margs, prs_arg->fmc_vtr[idx],*this); 
				
#line 1486 "ncoTree.cpp"
			}
			break;
		}
		case DIM_ID_SIZE:
		{
			dval = _t;
			match(_t,DIM_ID_SIZE);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2162 "ncoGrammer.g"
				
				string sDim=dval->getText();
				dmn_sct *dmn_fd;
				
				// Check output 
				dmn_fd=prs_arg->dmn_out_vtr.find(sDim);
				// Check input
				if(dmn_fd==NULL_CEWI)
				dmn_fd=prs_arg->dmn_in_vtr.find(sDim);
				
				// nb there is  a problem with the below code 
				// if we have a netcdf4 file and on the intial scan dim is undefined (dmn_fd==NULL)     
				// and on the final scan  size >NC_MAX_INT then there is a conflict between 
				// the initial returned  type (NC_INT) and the final returned type (NC_INT64)
				
				// csz 20100119 Workaround dependence on NC_MAX_INT which DNE in netcdf.h until ~2009
				#ifndef NC_MAX_INT
				#define NC_MAX_INT 2147483647
				#endif
				//Initial Scan
				if(prs_arg->ntl_scn){  
				if( (dmn_fd==NULL_CEWI )|| (dmn_fd->sz <= NC_MAX_INT) )
				var=ncap_sclr_var_mk(static_cast<std::string>("~dmn"),(nc_type)NC_INT,false);
				else 
				var=ncap_sclr_var_mk(static_cast<std::string>("~dmn"),(nc_type)NC_INT64,false);
				
				}else{ 
				
				if( dmn_fd==NULL_CEWI )
				err_prn(fnc_nm,"Unable to locate dimension " +sDim+ " in input or output files ");
				
				
				if(dmn_fd->sz <= NC_MAX_INT )
				var=ncap_sclr_var_mk(static_cast<std::string>("~dmn"),(nco_int)dmn_fd->sz);
				else
				var=ncap_sclr_var_mk(static_cast<std::string>("~dmn"),(nco_int64)dmn_fd->sz); 
				} 
				
				
#line 1536 "ncoTree.cpp"
			}
			break;
		}
		case ATT_ID:
		{
			att = _t;
			match(_t,ATT_ID);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2249 "ncoGrammer.g"
				
				
				NcapVar *Nvar=NULL;
				
				if(prs_arg->ntl_scn)
				Nvar=prs_arg->int_vtr.find(att->getText());
				
				if(Nvar==NULL) 
				Nvar=prs_arg->var_vtr.find(att->getText());
				
				var=NULL_CEWI;    
				if(Nvar !=NULL)
				var=nco_var_dpl(Nvar->var);
				else    
				// Check input file for attribute
				var=ncap_att_init(att->getText(),prs_arg);
				
				if(!prs_arg->ntl_scn && var==NULL_CEWI ){
				err_prn(fnc_nm,"Unable to locate attribute " +att->getText()+ " in input or output files.");
				}
				
				// if att not found return undefined
				if(prs_arg->ntl_scn && var==NULL_CEWI )
				var=ncap_var_udf(att->getText().c_str());
				
				if(prs_arg->ntl_scn && var->val.vp !=NULL)
				var->val.vp=(void*)nco_free(var->val.vp);
				
				
#line 1576 "ncoTree.cpp"
			}
			break;
		}
		case VALUE_LIST:
		{
			vlst = _t;
			match(_t,VALUE_LIST);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2280 "ncoGrammer.g"
				
				var=value_list(vlst);
				
#line 1590 "ncoTree.cpp"
			}
			break;
		}
		case NSTRING:
		{
			str = _t;
			match(_t,NSTRING);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2285 "ncoGrammer.g"
				
				char *tsng;
				
				tsng=strdup(str->getText().c_str());
				(void)sng_ascii_trn(tsng);            
				var=(var_sct *)nco_malloc(sizeof(var_sct));
				/* Set defaults */
				(void)var_dfl_set(var); 
				/* Overwrite with attribute expression information */
				var->nm=strdup("~zz@string");
				var->nbr_dim=0;
				var->sz=strlen(tsng);
				var->type=NC_CHAR;
				if(!prs_arg->ntl_scn){
				var->val.vp=(void*)nco_malloc(var->sz*nco_typ_lng(NC_CHAR));
				(void)cast_void_nctype((nc_type)NC_CHAR,&var->val);
				strncpy(var->val.cp,tsng,(size_t)var->sz);  
				(void)cast_nctype_void((nc_type)NC_CHAR,&var->val);
				}
				tsng=(char*)nco_free(tsng);      
				
#line 1622 "ncoTree.cpp"
			}
			break;
		}
		case N4STRING:
		{
			str1 = _t;
			match(_t,N4STRING);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2308 "ncoGrammer.g"
				
				char *tsng;
				
				tsng=strdup(str1->getText().c_str());
				(void)sng_ascii_trn(tsng);            
				var=(var_sct *)nco_malloc(sizeof(var_sct));
				/* Set defaults */
				(void)var_dfl_set(var); 
				/* Overwrite with attribute expression information */
				var->nm=strdup("~zz@string");
				var->nbr_dim=0;
				var->sz=1;
				
				var->type=(nc_type)NC_STRING;
				if(!prs_arg->ntl_scn){
				
				// nb sngp is type char** a ragged array of chars
				// each string terminated by a (char*)NULL  
				var->val.vp=(void*)nco_malloc(nco_typ_lng((nc_type)NC_STRING));
				(void)cast_void_nctype((nc_type)NC_STRING,&var->val);
				
				var->val.sngp[0]=strdup(tsng);   
				
				(void)cast_nctype_void((nc_type)NC_STRING,&var->val);
				}
				tsng=(char*)nco_free(tsng);      
				
#line 1660 "ncoTree.cpp"
			}
			break;
		}
		case NCAP_FLOAT:
		{
			val_float = _t;
			match(_t,NCAP_FLOAT);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2338 "ncoGrammer.g"
				if(prs_arg->ntl_scn) var=ncap_sclr_var_mk(static_cast<std::string>("~float"),(nc_type)NC_FLOAT,false); else var=ncap_sclr_var_mk(static_cast<std::string>("~float"),static_cast<float>(std::strtod(val_float->getText().c_str(),(char **)NULL)));
#line 1672 "ncoTree.cpp"
			}
			break;
		}
		case NCAP_DOUBLE:
		{
			val_double = _t;
			match(_t,NCAP_DOUBLE);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2340 "ncoGrammer.g"
				if(prs_arg->ntl_scn) var=ncap_sclr_var_mk(static_cast<std::string>("~double"),(nc_type)NC_DOUBLE,false); else var=ncap_sclr_var_mk(static_cast<std::string>("~double"),strtod(val_double->getText().c_str(),(char **)NULL));
#line 1684 "ncoTree.cpp"
			}
			break;
		}
		case NCAP_INT:
		{
			val_int = _t;
			match(_t,NCAP_INT);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2342 "ncoGrammer.g"
				if(prs_arg->ntl_scn) var=ncap_sclr_var_mk(static_cast<std::string>("~int"),(nc_type)NC_INT,false); else var=ncap_sclr_var_mk(static_cast<std::string>("~int"),static_cast<nco_int>(std::strtol(val_int->getText().c_str(),(char **)NULL,NCO_SNG_CNV_BASE10)));
#line 1696 "ncoTree.cpp"
			}
			break;
		}
		case NCAP_SHORT:
		{
			val_short = _t;
			match(_t,NCAP_SHORT);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2344 "ncoGrammer.g"
				if(prs_arg->ntl_scn) var=ncap_sclr_var_mk(static_cast<std::string>("~short"),(nc_type)NC_SHORT,false); else var=ncap_sclr_var_mk(static_cast<std::string>("~short"),static_cast<nco_short>(std::strtol(val_short->getText().c_str(),(char **)NULL,NCO_SNG_CNV_BASE10)));
#line 1708 "ncoTree.cpp"
			}
			break;
		}
		case NCAP_BYTE:
		{
			val_byte = _t;
			match(_t,NCAP_BYTE);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2346 "ncoGrammer.g"
				if(prs_arg->ntl_scn) var=ncap_sclr_var_mk(static_cast<std::string>("~byte"),(nc_type)NC_BYTE,false); else var=ncap_sclr_var_mk(static_cast<std::string>("~byte"),static_cast<nco_byte>(std::strtol(val_byte->getText().c_str(),(char **)NULL,NCO_SNG_CNV_BASE10)));
#line 1720 "ncoTree.cpp"
			}
			break;
		}
		case NCAP_UBYTE:
		{
			val_ubyte = _t;
			match(_t,NCAP_UBYTE);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2351 "ncoGrammer.g"
				if(prs_arg->ntl_scn) var=ncap_sclr_var_mk(static_cast<std::string>("~ubyte"),(nc_type)NC_UBYTE,false); else var=ncap_sclr_var_mk(static_cast<std::string>("~ubyte"),static_cast<nco_ubyte>(std::strtoul(val_ubyte->getText().c_str(),(char **)NULL,NCO_SNG_CNV_BASE10)));
#line 1732 "ncoTree.cpp"
			}
			break;
		}
		case NCAP_USHORT:
		{
			val_ushort = _t;
			match(_t,NCAP_USHORT);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2355 "ncoGrammer.g"
				if(prs_arg->ntl_scn) var=ncap_sclr_var_mk(static_cast<std::string>("~ushort"),(nc_type)NC_USHORT,false); else var=ncap_sclr_var_mk(static_cast<std::string>("~ushort"),static_cast<nco_ushort>(std::strtoul(val_ushort->getText().c_str(),(char **)NULL,NCO_SNG_CNV_BASE10)));
#line 1744 "ncoTree.cpp"
			}
			break;
		}
		case NCAP_UINT:
		{
			val_uint = _t;
			match(_t,NCAP_UINT);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2357 "ncoGrammer.g"
				if(prs_arg->ntl_scn) var=ncap_sclr_var_mk(static_cast<std::string>("~uint"),(nc_type)NC_UINT,false); else var=ncap_sclr_var_mk(static_cast<std::string>("~uint"),static_cast<nco_uint>(std::strtoul(val_uint->getText().c_str(),(char **)NULL,NCO_SNG_CNV_BASE10)));
#line 1756 "ncoTree.cpp"
			}
			break;
		}
		case NCAP_INT64:
		{
			val_int64 = _t;
			match(_t,NCAP_INT64);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2359 "ncoGrammer.g"
				if(prs_arg->ntl_scn) var=ncap_sclr_var_mk(static_cast<std::string>("~int64"),(nc_type)NC_INT64,false); else var=ncap_sclr_var_mk(static_cast<std::string>("~int64"),sng2nbr(val_int64->getText(),nco_int64_CEWI));
#line 1768 "ncoTree.cpp"
			}
			break;
		}
		case NCAP_UINT64:
		{
			val_uint64 = _t;
			match(_t,NCAP_UINT64);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2363 "ncoGrammer.g"
				if(prs_arg->ntl_scn) var=ncap_sclr_var_mk(static_cast<std::string>("~uint64"),(nc_type)NC_UINT64,false); else var=ncap_sclr_var_mk(static_cast<std::string>("~uint64"),sng2nbr(val_uint64->getText(),nco_uint64_CEWI));
#line 1780 "ncoTree.cpp"
			}
			break;
		}
		default:
			bool synPredMatched278 = false;
			if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = ASTNULL;
			if (((_t->getType() == PLUS))) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t278 = _t;
				synPredMatched278 = true;
				inputState->guessing++;
				try {
					{
					ANTLR_USE_NAMESPACE(antlr)RefAST __t277 = _t;
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp163_AST_in = _t;
					match(_t,PLUS);
					_t = _t->getFirstChild();
					out(_t);
					_t = _retTree;
					out(_t);
					_t = _retTree;
					_t = __t277;
					_t = _t->getNextSibling();
					}
				}
				catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
					synPredMatched278 = false;
				}
				_t = __t278;
				inputState->guessing--;
			}
			if ( synPredMatched278 ) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t279 = _t;
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp164_AST_in = _t;
				match(_t,PLUS);
				_t = _t->getFirstChild();
				var1=out(_t);
				_t = _retTree;
				var2=out(_t);
				_t = _retTree;
				_t = __t279;
				_t = _t->getNextSibling();
				if ( inputState->guessing==0 ) {
#line 1999 "ncoGrammer.g"
					var=ncap_var_var_op(var1,var2, PLUS );
#line 1826 "ncoTree.cpp"
				}
			}
			else {
				bool synPredMatched282 = false;
				if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
					_t = ASTNULL;
				if (((_t->getType() == MINUS))) {
					ANTLR_USE_NAMESPACE(antlr)RefAST __t282 = _t;
					synPredMatched282 = true;
					inputState->guessing++;
					try {
						{
						ANTLR_USE_NAMESPACE(antlr)RefAST __t281 = _t;
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp165_AST_in = _t;
						match(_t,MINUS);
						_t = _t->getFirstChild();
						out(_t);
						_t = _retTree;
						out(_t);
						_t = _retTree;
						_t = __t281;
						_t = _t->getNextSibling();
						}
					}
					catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
						synPredMatched282 = false;
					}
					_t = __t282;
					inputState->guessing--;
				}
				if ( synPredMatched282 ) {
					ANTLR_USE_NAMESPACE(antlr)RefAST __t283 = _t;
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp166_AST_in = _t;
					match(_t,MINUS);
					_t = _t->getFirstChild();
					var1=out(_t);
					_t = _retTree;
					var2=out(_t);
					_t = _retTree;
					_t = __t283;
					_t = _t->getNextSibling();
					if ( inputState->guessing==0 ) {
#line 2001 "ncoGrammer.g"
						var=ncap_var_var_op(var1,var2, MINUS );
#line 1871 "ncoTree.cpp"
					}
				}
				else {
					bool synPredMatched287 = false;
					if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
						_t = ASTNULL;
					if (((_t->getType() == UTIMES))) {
						ANTLR_USE_NAMESPACE(antlr)RefAST __t287 = _t;
						synPredMatched287 = true;
						inputState->guessing++;
						try {
							{
							ANTLR_USE_NAMESPACE(antlr)RefAST __t285 = _t;
							ANTLR_USE_NAMESPACE(antlr)RefAST tmp167_AST_in = _t;
							match(_t,UTIMES);
							_t = _t->getFirstChild();
							ANTLR_USE_NAMESPACE(antlr)RefAST __t286 = _t;
							ANTLR_USE_NAMESPACE(antlr)RefAST tmp168_AST_in = _t;
							match(_t,POST_INC);
							_t = _t->getFirstChild();
							out(_t);
							_t = _retTree;
							_t = __t286;
							_t = _t->getNextSibling();
							_t = __t285;
							_t = _t->getNextSibling();
							}
						}
						catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
							synPredMatched287 = false;
						}
						_t = __t287;
						inputState->guessing--;
					}
					if ( synPredMatched287 ) {
						ANTLR_USE_NAMESPACE(antlr)RefAST __t288 = _t;
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp169_AST_in = _t;
						match(_t,UTIMES);
						_t = _t->getFirstChild();
						ANTLR_USE_NAMESPACE(antlr)RefAST __t289 = _t;
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp170_AST_in = _t;
						match(_t,POST_INC);
						_t = _t->getFirstChild();
						var1=out_asn(_t);
						_t = _retTree;
						_t = __t289;
						_t = _t->getNextSibling();
						_t = __t288;
						_t = _t->getNextSibling();
						if ( inputState->guessing==0 ) {
#line 2002 "ncoGrammer.g"
							
							var=ncap_var_var_inc(var1,NULL_CEWI,POST_INC,true,prs_arg);      
							
#line 1926 "ncoTree.cpp"
						}
					}
					else {
						bool synPredMatched293 = false;
						if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
							_t = ASTNULL;
						if (((_t->getType() == UTIMES))) {
							ANTLR_USE_NAMESPACE(antlr)RefAST __t293 = _t;
							synPredMatched293 = true;
							inputState->guessing++;
							try {
								{
								ANTLR_USE_NAMESPACE(antlr)RefAST __t291 = _t;
								ANTLR_USE_NAMESPACE(antlr)RefAST tmp171_AST_in = _t;
								match(_t,UTIMES);
								_t = _t->getFirstChild();
								ANTLR_USE_NAMESPACE(antlr)RefAST __t292 = _t;
								ANTLR_USE_NAMESPACE(antlr)RefAST tmp172_AST_in = _t;
								match(_t,POST_DEC);
								_t = _t->getFirstChild();
								out(_t);
								_t = _retTree;
								_t = __t292;
								_t = _t->getNextSibling();
								_t = __t291;
								_t = _t->getNextSibling();
								}
							}
							catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
								synPredMatched293 = false;
							}
							_t = __t293;
							inputState->guessing--;
						}
						if ( synPredMatched293 ) {
							ANTLR_USE_NAMESPACE(antlr)RefAST __t294 = _t;
							ANTLR_USE_NAMESPACE(antlr)RefAST tmp173_AST_in = _t;
							match(_t,UTIMES);
							_t = _t->getFirstChild();
							ANTLR_USE_NAMESPACE(antlr)RefAST __t295 = _t;
							ANTLR_USE_NAMESPACE(antlr)RefAST tmp174_AST_in = _t;
							match(_t,POST_DEC);
							_t = _t->getFirstChild();
							var1=out_asn(_t);
							_t = _retTree;
							_t = __t295;
							_t = _t->getNextSibling();
							_t = __t294;
							_t = _t->getNextSibling();
							if ( inputState->guessing==0 ) {
#line 2005 "ncoGrammer.g"
								
								var=ncap_var_var_inc(var1,NULL_CEWI,POST_DEC,true,prs_arg);      
								
#line 1981 "ncoTree.cpp"
							}
						}
						else {
							bool synPredMatched299 = false;
							if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
								_t = ASTNULL;
							if (((_t->getType() == UTIMES))) {
								ANTLR_USE_NAMESPACE(antlr)RefAST __t299 = _t;
								synPredMatched299 = true;
								inputState->guessing++;
								try {
									{
									ANTLR_USE_NAMESPACE(antlr)RefAST __t297 = _t;
									ANTLR_USE_NAMESPACE(antlr)RefAST tmp175_AST_in = _t;
									match(_t,UTIMES);
									_t = _t->getFirstChild();
									ANTLR_USE_NAMESPACE(antlr)RefAST __t298 = _t;
									ANTLR_USE_NAMESPACE(antlr)RefAST tmp176_AST_in = _t;
									match(_t,INC);
									_t = _t->getFirstChild();
									out(_t);
									_t = _retTree;
									_t = __t298;
									_t = _t->getNextSibling();
									_t = __t297;
									_t = _t->getNextSibling();
									}
								}
								catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
									synPredMatched299 = false;
								}
								_t = __t299;
								inputState->guessing--;
							}
							if ( synPredMatched299 ) {
								ANTLR_USE_NAMESPACE(antlr)RefAST __t300 = _t;
								ANTLR_USE_NAMESPACE(antlr)RefAST tmp177_AST_in = _t;
								match(_t,UTIMES);
								_t = _t->getFirstChild();
								ANTLR_USE_NAMESPACE(antlr)RefAST __t301 = _t;
								ANTLR_USE_NAMESPACE(antlr)RefAST tmp178_AST_in = _t;
								match(_t,INC);
								_t = _t->getFirstChild();
								var1=out_asn(_t);
								_t = _retTree;
								_t = __t301;
								_t = _t->getNextSibling();
								_t = __t300;
								_t = _t->getNextSibling();
								if ( inputState->guessing==0 ) {
#line 2008 "ncoGrammer.g"
									
									var=ncap_var_var_inc(var1,NULL_CEWI,INC,true,prs_arg);      
									
#line 2036 "ncoTree.cpp"
								}
							}
							else {
								bool synPredMatched305 = false;
								if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
									_t = ASTNULL;
								if (((_t->getType() == UTIMES))) {
									ANTLR_USE_NAMESPACE(antlr)RefAST __t305 = _t;
									synPredMatched305 = true;
									inputState->guessing++;
									try {
										{
										ANTLR_USE_NAMESPACE(antlr)RefAST __t303 = _t;
										ANTLR_USE_NAMESPACE(antlr)RefAST tmp179_AST_in = _t;
										match(_t,UTIMES);
										_t = _t->getFirstChild();
										ANTLR_USE_NAMESPACE(antlr)RefAST __t304 = _t;
										ANTLR_USE_NAMESPACE(antlr)RefAST tmp180_AST_in = _t;
										match(_t,DEC);
										_t = _t->getFirstChild();
										out(_t);
										_t = _retTree;
										_t = __t304;
										_t = _t->getNextSibling();
										_t = __t303;
										_t = _t->getNextSibling();
										}
									}
									catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
										synPredMatched305 = false;
									}
									_t = __t305;
									inputState->guessing--;
								}
								if ( synPredMatched305 ) {
									ANTLR_USE_NAMESPACE(antlr)RefAST __t306 = _t;
									ANTLR_USE_NAMESPACE(antlr)RefAST tmp181_AST_in = _t;
									match(_t,UTIMES);
									_t = _t->getFirstChild();
									ANTLR_USE_NAMESPACE(antlr)RefAST __t307 = _t;
									ANTLR_USE_NAMESPACE(antlr)RefAST tmp182_AST_in = _t;
									match(_t,DEC);
									_t = _t->getFirstChild();
									var1=out_asn(_t);
									_t = _retTree;
									_t = __t307;
									_t = _t->getNextSibling();
									_t = __t306;
									_t = _t->getNextSibling();
									if ( inputState->guessing==0 ) {
#line 2011 "ncoGrammer.g"
										
										var=ncap_var_var_inc(var1,NULL_CEWI,DEC,true,prs_arg);      
										
#line 2091 "ncoTree.cpp"
									}
								}
								else if ((_t->getType() == MINUS)) {
									ANTLR_USE_NAMESPACE(antlr)RefAST __t313 = _t;
									ANTLR_USE_NAMESPACE(antlr)RefAST tmp183_AST_in = _t;
									match(_t,MINUS);
									_t = _t->getFirstChild();
									var1=out(_t);
									_t = _retTree;
									_t = __t313;
									_t = _t->getNextSibling();
									if ( inputState->guessing==0 ) {
#line 2028 "ncoGrammer.g"
										var=ncap_var_var_op(var1,NULL_CEWI, MINUS );
#line 2106 "ncoTree.cpp"
									}
								}
								else if ((_t->getType() == PLUS)) {
									ANTLR_USE_NAMESPACE(antlr)RefAST __t314 = _t;
									ANTLR_USE_NAMESPACE(antlr)RefAST tmp184_AST_in = _t;
									match(_t,PLUS);
									_t = _t->getFirstChild();
									var1=out(_t);
									_t = _retTree;
									_t = __t314;
									_t = _t->getNextSibling();
								}
								else {
									bool synPredMatched340 = false;
									if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
										_t = ASTNULL;
									if (((_t->getType() == VAR_ID))) {
										ANTLR_USE_NAMESPACE(antlr)RefAST __t340 = _t;
										synPredMatched340 = true;
										inputState->guessing++;
										try {
											{
											ANTLR_USE_NAMESPACE(antlr)RefAST __t339 = _t;
											ANTLR_USE_NAMESPACE(antlr)RefAST tmp185_AST_in = _t;
											match(_t,VAR_ID);
											_t = _t->getFirstChild();
											ANTLR_USE_NAMESPACE(antlr)RefAST tmp186_AST_in = _t;
											match(_t,LMT_LIST);
											_t = _t->getNextSibling();
											_t = __t339;
											_t = _t->getNextSibling();
											}
										}
										catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
											synPredMatched340 = false;
										}
										_t = __t340;
										inputState->guessing--;
									}
									if ( synPredMatched340 ) {
										ANTLR_USE_NAMESPACE(antlr)RefAST __t341 = _t;
										vid = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
										match(_t,VAR_ID);
										_t = _t->getFirstChild();
										lmt = _t;
										match(_t,LMT_LIST);
										_t = _t->getNextSibling();
										_t = __t341;
										_t = _t->getNextSibling();
										if ( inputState->guessing==0 ) {
#line 2203 "ncoGrammer.g"
											
													
													    // fxm: 4 Oct 2015
														/*
														  the following is valid syntx var_nm(array_var)-
														  array_var now contains all the indices - that is 
														  srt vectors  
														  srt & end vectors
														  srt,end,srd vectors
														
														  so for now indexing into a multi-dmensional var using a single index has
														  temporarily been disabled
														
											// see if hyperslab limit is a single value
											if(lmt->getNumberOfChildren()==1 && 
											lmt->getFirstChild()->getNumberOfChildren()==1 &&
											lmt->getFirstChild()->getFirstChild()->getType() != COLON)
											
											var=var_lmt_one(vid);
											else   
											var=var_lmt(vid);
											*/
											var=var_lmt(vid);  
											
											
											
#line 2184 "ncoTree.cpp"
										}
									}
									else if ((_t->getType() == VAR_ID)) {
										v = _t;
										match(_t,VAR_ID);
										_t = _t->getNextSibling();
										if ( inputState->guessing==0 ) {
#line 2232 "ncoGrammer.g"
											
											
											var=prs_arg->ncap_var_init(v->getText(),true);
											if(var== NULL){
											if(prs_arg->ntl_scn){
											var=ncap_var_udf(v->getText().c_str());
											return var;
											}else
											nco_exit(EXIT_FAILURE);
											}
											
											// apply cast only if sz >1 
											if(bcst && var->sz >1)
											var=ncap_cst_do(var,var_cst,prs_arg->ntl_scn);
											
#line 2208 "ncoTree.cpp"
										}
									}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(_t);
		}
		}}}}}}}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return var;
}

var_sct * ncoTree::assign_ntl(ANTLR_USE_NAMESPACE(antlr)RefAST _t,
	bool bram
) {
#line 1449 "ncoGrammer.g"
	var_sct *var;
#line 2234 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST assign_ntl_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST lmt = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid1 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST dmn = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid2 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST att = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST att1 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST att2 = ANTLR_USE_NAMESPACE(antlr)nullAST;
#line 1449 "ncoGrammer.g"
	
	const std::string fnc_nm("assign_ntl"); 
	var=NULL_CEWI;
	
#line 2249 "ncoTree.cpp"
	
	try {      // for error handling
		bool synPredMatched244 = false;
		if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = ASTNULL;
		if (((_t->getType() == VAR_ID))) {
			ANTLR_USE_NAMESPACE(antlr)RefAST __t244 = _t;
			synPredMatched244 = true;
			inputState->guessing++;
			try {
				{
				ANTLR_USE_NAMESPACE(antlr)RefAST __t243 = _t;
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp187_AST_in = _t;
				match(_t,VAR_ID);
				_t = _t->getFirstChild();
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp188_AST_in = _t;
				match(_t,LMT_LIST);
				_t = _t->getNextSibling();
				_t = __t243;
				_t = _t->getNextSibling();
				}
			}
			catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
				synPredMatched244 = false;
			}
			_t = __t244;
			inputState->guessing--;
		}
		if ( synPredMatched244 ) {
			ANTLR_USE_NAMESPACE(antlr)RefAST __t245 = _t;
			vid = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
			match(_t,VAR_ID);
			_t = _t->getFirstChild();
			lmt = _t;
			match(_t,LMT_LIST);
			_t = _t->getNextSibling();
			_t = __t245;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1454 "ncoGrammer.g"
				
				
				std::string var_nm; 
				var_sct *var_lhs;
				var_sct *var_rhs;
				NcapVar *Nvar;              
				
				var_nm=vid->getText();
				
				if(nco_dbg_lvl_get() >= nco_dbg_scl) dbg_prn(fnc_nm,var_nm+"(limits)");
				
				// evaluate rhs for side effects eg new dims or lvalues 
				var_rhs=out(vid->getNextSibling());         
				var_rhs=nco_var_free(var_rhs);               
				
				var_lhs=prs_arg->ncap_var_init(var_nm,false);
				if(var_lhs){
				var=nco_var_dpl(var_lhs);
				(void)prs_arg->ncap_var_write(var_lhs,bram);
				} else {
				// set var to udf
				var_lhs=ncap_var_udf(var_nm.c_str());
				var=nco_var_dpl(var_lhs);
				
				Nvar=new NcapVar(var_lhs);
				(void)prs_arg->int_vtr.push_ow(Nvar);
				}
				
#line 2318 "ncoTree.cpp"
			}
		}
		else {
			bool synPredMatched248 = false;
			if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = ASTNULL;
			if (((_t->getType() == VAR_ID))) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t248 = _t;
				synPredMatched248 = true;
				inputState->guessing++;
				try {
					{
					ANTLR_USE_NAMESPACE(antlr)RefAST __t247 = _t;
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp189_AST_in = _t;
					match(_t,VAR_ID);
					_t = _t->getFirstChild();
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp190_AST_in = _t;
					match(_t,DMN_LIST);
					_t = _t->getNextSibling();
					_t = __t247;
					_t = _t->getNextSibling();
					}
				}
				catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
					synPredMatched248 = false;
				}
				_t = __t248;
				inputState->guessing--;
			}
			if ( synPredMatched248 ) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t249 = _t;
				vid1 = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
				match(_t,VAR_ID);
				_t = _t->getFirstChild();
				dmn = _t;
				match(_t,DMN_LIST);
				_t = _t->getNextSibling();
				_t = __t249;
				_t = _t->getNextSibling();
				if ( inputState->guessing==0 ) {
#line 1483 "ncoGrammer.g"
					
					
					int idx;
					std::string var_nm;
					var_sct *var1;
					std::vector<std::string> str_vtr;
					RefAST  aRef;
					NcapVar *Nvar;
					int str_vtr_sz;
					
					var_nm=vid1->getText();               
					
					if(nco_dbg_lvl_get() >= nco_dbg_var) dbg_prn(fnc_nm,var_nm+"[dims]");
					
					// set class wide variables
					bcst=true;  
					var_cst=NULL_CEWI;
					
					aRef=dmn->getFirstChild();
					
					// pPut dimension names in vector       
					while(aRef) {
					str_vtr.push_back(aRef->getText());
					aRef=aRef->getNextSibling();      
					}
					
					//Check that all dims exist
					str_vtr_sz=str_vtr.size();
					for(idx=0 ; idx < str_vtr_sz ; idx++)
					if(   prs_arg->dmn_in_vtr.findi(str_vtr[idx]) ==-1             
					&& prs_arg->dmn_out_vtr.findi(str_vtr[idx]) ==-1)      
					break;
					
					// return undef if dim missing 
					if( idx <str_vtr_sz){
					var=NULL_CEWI;
					} else {
					// Cast is applied in VAR_ID action in function out()
					var_cst=ncap_cst_mk(str_vtr,prs_arg);
					
					var1=out(vid1->getNextSibling());
					if(var1->undefined) {
					var=NULL_CEWI;
					} else {
					var_cst=nco_var_cnf_typ(var1->type,var_cst);
					var_cst->typ_dsk=var1->type;
					var=nco_var_dpl(var_cst);
					}
					var1=nco_var_free(var1);
					}
					
					if(!var){
					var1=ncap_var_udf(var_nm.c_str());
					Nvar=new NcapVar(var1);
					(void)prs_arg->int_vtr.push_ow(Nvar);
					var=nco_var_dpl(var1);
					} else{
					var->nm=(char*)nco_free(var->nm);
					var->nm=strdup(var_nm.c_str());
					var1=nco_var_dpl(var);
					prs_arg->ncap_var_write(var1,bram);
					}
					
					if(var_cst)
					var_cst=nco_var_free(var_cst);
					
					bcst=false;   
					
#line 2428 "ncoTree.cpp"
				}
			}
			else if ((_t->getType() == VAR_ID)) {
				vid2 = _t;
				match(_t,VAR_ID);
				_t = _t->getNextSibling();
				if ( inputState->guessing==0 ) {
#line 1552 "ncoGrammer.g"
					
					
					std::string var_nm;
					
					var_nm=vid2->getText();
					
					if(nco_dbg_lvl_get() >= nco_dbg_var) dbg_prn(fnc_nm,var_nm);
					
					var_sct *var1;
					
					// Set class wide variables           
					bcst=false;
					var_cst=NULL_CEWI; 
					
					// get shape from RHS
					var1=out(vid2->getNextSibling());
					(void)nco_free(var1->nm);                
					var1->nm =strdup(var_nm.c_str());
					
					//Copy return variable
					var=nco_var_dpl(var1);
					
					// Write var to int_vtr
					// if var already in int_vtr or var_vtr then write call does nothing
					(void)prs_arg->ncap_var_write(var1,bram);
					//(void)ncap_var_write_omp(var1,bram,prs_arg);
					
					
#line 2465 "ncoTree.cpp"
				}
			}
			else {
				bool synPredMatched252 = false;
				if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
					_t = ASTNULL;
				if (((_t->getType() == ATT_ID))) {
					ANTLR_USE_NAMESPACE(antlr)RefAST __t252 = _t;
					synPredMatched252 = true;
					inputState->guessing++;
					try {
						{
						ANTLR_USE_NAMESPACE(antlr)RefAST __t251 = _t;
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp191_AST_in = _t;
						match(_t,ATT_ID);
						_t = _t->getFirstChild();
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp192_AST_in = _t;
						match(_t,LMT_LIST);
						_t = _t->getNextSibling();
						_t = __t251;
						_t = _t->getNextSibling();
						}
					}
					catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
						synPredMatched252 = false;
					}
					_t = __t252;
					inputState->guessing--;
				}
				if ( synPredMatched252 ) {
					ANTLR_USE_NAMESPACE(antlr)RefAST __t253 = _t;
					att = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
					match(_t,ATT_ID);
					_t = _t->getFirstChild();
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp193_AST_in = _t;
					match(_t,LMT_LIST);
					_t = _t->getNextSibling();
					_t = __t253;
					_t = _t->getNextSibling();
					if ( inputState->guessing==0 ) {
#line 1581 "ncoGrammer.g"
						
						;
						
#line 2510 "ncoTree.cpp"
					}
				}
				else {
					bool synPredMatched256 = false;
					if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
						_t = ASTNULL;
					if (((_t->getType() == ATT_ID))) {
						ANTLR_USE_NAMESPACE(antlr)RefAST __t256 = _t;
						synPredMatched256 = true;
						inputState->guessing++;
						try {
							{
							ANTLR_USE_NAMESPACE(antlr)RefAST __t255 = _t;
							ANTLR_USE_NAMESPACE(antlr)RefAST tmp194_AST_in = _t;
							match(_t,ATT_ID);
							_t = _t->getFirstChild();
							ANTLR_USE_NAMESPACE(antlr)RefAST tmp195_AST_in = _t;
							match(_t,LMT_DMN);
							_t = _t->getNextSibling();
							_t = __t255;
							_t = _t->getNextSibling();
							}
						}
						catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
							synPredMatched256 = false;
						}
						_t = __t256;
						inputState->guessing--;
					}
					if ( synPredMatched256 ) {
						ANTLR_USE_NAMESPACE(antlr)RefAST __t257 = _t;
						att1 = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
						match(_t,ATT_ID);
						_t = _t->getFirstChild();
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp196_AST_in = _t;
						match(_t,DMN_LIST);
						_t = _t->getNextSibling();
						_t = __t257;
						_t = _t->getNextSibling();
						if ( inputState->guessing==0 ) {
#line 1584 "ncoGrammer.g"
							
							;
							
#line 2555 "ncoTree.cpp"
						}
					}
					else if ((_t->getType() == ATT_ID)) {
						att2 = _t;
						match(_t,ATT_ID);
						_t = _t->getNextSibling();
						if ( inputState->guessing==0 ) {
#line 1587 "ncoGrammer.g"
							
							
							//In Initial scan all newly defined atts are flagged as Undefined
							var_sct *var1;
							NcapVar *Nvar;
							
							if(nco_dbg_lvl_get() > nco_dbg_var) dbg_prn(fnc_nm,att2->getText());
							
							var1=ncap_var_udf(att2->getText().c_str());
							
							Nvar=new NcapVar(var1);
							prs_arg->int_vtr.push_ow(Nvar);          
							
							// Copy return variable
							var=nco_var_dpl(var1);    
							
							
#line 2581 "ncoTree.cpp"
						}
					}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(_t);
		}
		}}}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return var;
}

var_sct * ncoTree::assign(ANTLR_USE_NAMESPACE(antlr)RefAST _t,
	bool bram
) {
#line 1607 "ncoGrammer.g"
	var_sct *var;
#line 2607 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST assign_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST lmt = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid1 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST dmn = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid2 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST att = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST att1 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST att2 = ANTLR_USE_NAMESPACE(antlr)nullAST;
#line 1607 "ncoGrammer.g"
	
	const std::string fnc_nm("assign"); 
	var=NULL_CEWI;
	
#line 2622 "ncoTree.cpp"
	
	try {      // for error handling
		bool synPredMatched261 = false;
		if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = ASTNULL;
		if (((_t->getType() == VAR_ID))) {
			ANTLR_USE_NAMESPACE(antlr)RefAST __t261 = _t;
			synPredMatched261 = true;
			inputState->guessing++;
			try {
				{
				ANTLR_USE_NAMESPACE(antlr)RefAST __t260 = _t;
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp197_AST_in = _t;
				match(_t,VAR_ID);
				_t = _t->getFirstChild();
				ANTLR_USE_NAMESPACE(antlr)RefAST tmp198_AST_in = _t;
				match(_t,LMT_LIST);
				_t = _t->getNextSibling();
				_t = __t260;
				_t = _t->getNextSibling();
				}
			}
			catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
				synPredMatched261 = false;
			}
			_t = __t261;
			inputState->guessing--;
		}
		if ( synPredMatched261 ) {
			ANTLR_USE_NAMESPACE(antlr)RefAST __t262 = _t;
			vid = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
			match(_t,VAR_ID);
			_t = _t->getFirstChild();
			lmt = _t;
			match(_t,LMT_LIST);
			_t = _t->getNextSibling();
			_t = __t262;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 1613 "ncoGrammer.g"
				
				
				int idx;
				int nbr_dmn;
				int var_id; 
				int slb_sz;
				std::string var_nm;
				
				RefAST lmt_Ref;
				var_sct *var_lhs=NULL_CEWI;
				var_sct *var_rhs=NULL_CEWI;
				NcapVector<lmt_sct*> lmt_vtr;          
				
				lmt_Ref=vid->getFirstChild();
				
				bcst=false;
				var_cst=NULL_CEWI;
				var=NULL_CEWI;
				NcapVar *Nvar; 
				
				var_nm=vid->getText();
				
				if(nco_dbg_lvl_get() >= nco_dbg_var) dbg_prn(fnc_nm,var_nm+"(limits)");
				
				// check to see if we are dealing with a single
				// index in limit -- i.e hyperslab a mult-dimensional var
				// with a single index 
				
				if(lmt->getNumberOfChildren()==1 && 
				lmt->getFirstChild()->getNumberOfChildren()==1 &&
				lmt->getFirstChild()->getFirstChild()->getType() != COLON
				){
				var=var_lmt_one_lhs(vid,bram);
				goto end0;
				} 
				
				lmt_Ref=lmt;               
				
				Nvar=prs_arg->var_vtr.find(var_nm);
				
				// Overwrite bram possibly 
				if(Nvar) 
				bram=Nvar->flg_mem;
				
				// Deal with RAM variables
				if(bram) {
				
				if(Nvar && Nvar->flg_stt==1){
				var_sct *var_ini;
				var_ini=prs_arg->ncap_var_init(var_nm,true);       
				Nvar->var->val.vp=var_ini->val.vp;
				var_ini->val.vp=(void*)NULL;
				var_ini=nco_var_free(var_ini);
				Nvar->flg_stt=2; 
				}
				
				if(Nvar && Nvar->flg_stt==2)
				var_lhs=Nvar->var;    
				
				if(!Nvar)
				var_lhs=prs_arg->ncap_var_init(var_nm,true);       
				
				nbr_dmn=var_lhs->nbr_dim;
				
				// Now populate lmt_vtr;
				if( lmt_mk(nbr_dmn, lmt_Ref,lmt_vtr) == false)
				err_prn(fnc_nm,"Invalid hyperslab limits for variable "+ var_nm);
				
				if( lmt_vtr.size() != nbr_dmn)
				err_prn(fnc_nm,"Number of hyperslab limits for variable "+ var_nm+" doesn't match number of dimensions");
				
				// add dim names to dimension list 
				for(idx=0 ; idx < nbr_dmn;idx++) 
				lmt_vtr[idx]->nm=strdup(var_lhs->dim[idx]->nm);   
				
				slb_sz=1;        
				// fill out limit structure
				for(idx=0 ; idx < nbr_dmn ;idx++){
				(void)ncap_lmt_evl(prs_arg->out_id,lmt_vtr[idx],prs_arg);
				// Calculate size
				slb_sz *= lmt_vtr[idx]->cnt;
				}
				// Calculate RHS variable                  
				var_rhs=out(vid->getNextSibling());         
				// Convert to LHS type
				var_rhs=nco_var_cnf_typ(var_lhs->type,var_rhs);             
				
				// deal with scalar on RHS first         
				if(var_rhs->sz == 1)
				(void)ncap_att_stretch(var_rhs,slb_sz);
				
				// make sure var_lhs and var_rhs are the same size
				// and that they are the same shape (ie they conform!!)          
				if(var_rhs->sz != slb_sz){
				err_prn(fnc_nm, "Hyperslab for "+var_nm+" - number of elements on LHS(" +nbr2sng(slb_sz) +  ") doesn't equal number of elements on RHS(" +nbr2sng(var_rhs->sz) +  ")");                                       
				}
				
				(void)nco_put_var_mem(var_rhs,var_lhs,lmt_vtr);
				if(Nvar==NULL)
				(void)prs_arg->ncap_var_write(var_lhs,true); 
				
				// deal with Regular Vars
				} else {                 
				
				// if var undefined in O or defined but not populated
				if(!Nvar || ( Nvar && Nvar->flg_stt==1)){              
				// if var isn't in ouptut then copy it there
				//rcd=nco_inq_varid_flg(prs_arg->out_id,var_nm,&var_id);
				
				var_lhs=prs_arg->ncap_var_init(var_nm,true);
				
				// copy atts to output
				(void)ncap_att_cpy(var_nm,var_nm,prs_arg);
				(void)prs_arg->ncap_var_write(var_lhs,false);
				
				wrn_prn(fnc_nm,"Var being read and written in ASSIGN "+ var_nm); 
				}
				
				// Get "new" var_id   
				(void)nco_inq_varid(prs_arg->out_id,var_nm.c_str(),&var_id);
				
				var_lhs=prs_arg->ncap_var_init(var_nm,false);
				
				nbr_dmn=var_lhs->nbr_dim;
				
				// Now populate lmt_vtr;
				if( lmt_mk(nbr_dmn, lmt_Ref,lmt_vtr) == false)
				err_prn(fnc_nm,"Invalid hyperslab limits for variable "+ var_nm);
				
				if( lmt_vtr.size() != nbr_dmn)
				err_prn(fnc_nm,"Number of hyperslab limits for variable "+ var_nm+" doesn't match number of dimensions");
				
				// add dim names to dimension list 
				for(idx=0 ; idx < nbr_dmn;idx++) 
				lmt_vtr[idx]->nm=strdup(var_lhs->dim[idx]->nm);   
				
				var_lhs->sz=1;        
				// fill out limit structure
				for(idx=0 ; idx < nbr_dmn ;idx++){
				(void)ncap_lmt_evl(prs_arg->out_id,lmt_vtr[idx],prs_arg);
				// Calculate size
				var_lhs->sz *= lmt_vtr[idx]->cnt;
				}
				// Calculate RHS variable                  
				var_rhs=out(vid->getNextSibling());         
				// Convert to LHS type
				var_rhs=nco_var_cnf_typ(var_lhs->type,var_rhs);             
				
				// deal with scalar on RHS first         
				if(var_rhs->sz == 1){
				// stretch variable to var_lhs->sz                 
				(void)ncap_att_stretch(var_rhs,var_lhs->sz);
				}
				
				// make sure var_lhs and var_rhs are the same size
				// and that they are the same shape (ie they conform!!)          
				if(var_rhs->sz != var_lhs->sz){
				err_prn(fnc_nm, "Hyperslab for "+var_nm+" - number of elements on LHS(" +nbr2sng(var_lhs->sz) +  ") doesn't equal number of elements on RHS(" +nbr2sng(var_rhs->sz) +  ")");                                       
				}
				
				// swap values about
				var_lhs->val.vp=var_rhs->val.vp; 
				var_rhs->val.vp=(void*)NULL; 
				
				//write block              
				{ 
				for(idx=0;idx<nbr_dmn;idx++){
				var_lhs->srt[idx]=lmt_vtr[idx]->srt; 
				var_lhs->cnt[idx]=lmt_vtr[idx]->cnt; 
				var_lhs->srd[idx]=lmt_vtr[idx]->srd; 
				} /* end loop over idx */
				
				
				// write slab to O contains call to Open MP critical region
				// routine also frees up calling var    
				(void)prs_arg->ncap_var_write_slb(var_lhs);     
				
				
				} // end put block !!
				
				} // end else if regular var
				
				var_rhs=nco_var_free(var_rhs);
				
				// Empty and free vector 
				for(idx=0 ; idx < nbr_dmn ; idx++)
				(void)nco_lmt_free(lmt_vtr[idx]);
				
				// See If we have to return something
				end0:         if(lmt->getNextSibling() && lmt->getNextSibling()->getType()==NORET)
				var=NULL_CEWI;
				else 
				var=prs_arg->ncap_var_init(var_nm,true);
				
				
#line 2858 "ncoTree.cpp"
			}
		}
		else {
			bool synPredMatched265 = false;
			if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = ASTNULL;
			if (((_t->getType() == VAR_ID))) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t265 = _t;
				synPredMatched265 = true;
				inputState->guessing++;
				try {
					{
					ANTLR_USE_NAMESPACE(antlr)RefAST __t264 = _t;
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp199_AST_in = _t;
					match(_t,VAR_ID);
					_t = _t->getFirstChild();
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp200_AST_in = _t;
					match(_t,DMN_LIST);
					_t = _t->getNextSibling();
					_t = __t264;
					_t = _t->getNextSibling();
					}
				}
				catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
					synPredMatched265 = false;
				}
				_t = __t265;
				inputState->guessing--;
			}
			if ( synPredMatched265 ) {
				ANTLR_USE_NAMESPACE(antlr)RefAST __t266 = _t;
				vid1 = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
				match(_t,VAR_ID);
				_t = _t->getFirstChild();
				dmn = _t;
				match(_t,DMN_LIST);
				_t = _t->getNextSibling();
				_t = __t266;
				_t = _t->getNextSibling();
				if ( inputState->guessing==0 ) {
#line 1810 "ncoGrammer.g"
					
					
					var_sct *var1;
					std::vector<std::string> str_vtr;
					RefAST  aRef;
					std::string var_nm;              
					
					var_nm=vid1->getText();
					
					if(nco_dbg_lvl_get() >= nco_dbg_var) dbg_prn(fnc_nm,var_nm+"[dims]");
					
					// set class wide variables
					bcst=true;  
					var_cst=NULL_CEWI;
					
					//aRef=vid->getFirstChild()->getFirstChild();
					aRef=dmn->getFirstChild();
					
					// pPut dimension names in vector       
					while(aRef) {
					str_vtr.push_back(aRef->getText());
					aRef=aRef->getNextSibling();      
					}
					
					// Cast is applied in VAR_ID action in function out()
					// Note cast is NOT applied to an attribute, an irregular hyperslab
					// or any entity which has a size of one.
					var_cst=ncap_cst_mk(str_vtr,prs_arg);     
					var1=out(vid1->getNextSibling());
					
					/* NB var_cst->val.vp always now set to null */ 
					
					
					// If the RHS has size one or is an attribute or an irregular hyperslab
					// then we neet to use the var_cst as the shape of the written variable.
					// It is possible for the cast on the LHS to have a size of one and the RHS 
					// to have a size of one e.g., if the dim(s) in the list have a size of one   
					bool br1=(var_cst->sz >=1 && var1->sz==1);
					bool br2=(var_cst->sz==var1->sz &&  ( ncap_var_is_att(var1) ||var1->has_dpl_dmn==-1 ));
					
					// The code rebuilds var1 with the shape from the casting variable  
					if( br1 || br2){
					var_sct *var_nw;
					void *vp_swp;
					
					var_nw=nco_var_dpl(var_cst);
					var_nw=nco_var_cnf_typ(var1->type,var_nw);
					if(br1)
					(void)ncap_att_stretch(var1,var_nw->sz);
					
					vp_swp=var_nw->val.vp;
					var_nw->val.vp=var1->val.vp;
					var1->val.vp=vp_swp;
					
					var1=nco_var_free(var1);
					var1=var_nw;
					}
					
					//blow out if vars not the same size      
					if(var1->sz != var_cst->sz) 
					err_prn(fnc_nm, "LHS cast for "+var_nm+" - cannot make RHS "+ std::string(var1->nm) + " conform.");          
					var1->nm=(char*)nco_free(var1->nm);
					var1->nm =strdup(var_nm.c_str());
					
					// See If we have to return something
					if(dmn->getNextSibling() && dmn->getNextSibling()->getType()==NORET)
					var=NULL_CEWI;
					else 
					var=nco_var_dpl(var1);     
					
					//call to nco_var_get() in ncap_var_init() uses this property
					var1->typ_dsk=var1->type;
					(void)prs_arg->ncap_var_write(var1,bram);
					
					bcst=false;
					var_cst=nco_var_free(var_cst); 
					
					
#line 2978 "ncoTree.cpp"
				}
			}
			else if ((_t->getType() == VAR_ID)) {
				vid2 = _t;
				match(_t,VAR_ID);
				_t = _t->getNextSibling();
				if ( inputState->guessing==0 ) {
#line 1889 "ncoGrammer.g"
					
					// Set class wide variables
					var_sct *var1;
					NcapVar *Nvar;
					std::string var_nm;
					
					var_nm=vid2->getText();       
					
					if(nco_dbg_lvl_get() >= nco_dbg_var) dbg_prn(fnc_nm,var_nm);
					
					bcst=false;
					var_cst=NULL_CEWI; 
					
					var1=out(vid2->getNextSibling());
					
					// Save name 
					std::string s_var_rhs(var1->nm);
					(void)nco_free(var1->nm);                
					var1->nm =strdup(var_nm.c_str());
					
					// Do attribute propagation only if
					// var doesn't already exist or is defined but NOT
					// populated
					Nvar=prs_arg->var_vtr.find(vid2->getText());
					//rcd=nco_inq_varid_flg(prs_arg->out_id,var1->nm ,&var_id);
					
					if(!Nvar || (Nvar && Nvar->flg_stt==1))
					(void)ncap_att_cpy(var_nm,s_var_rhs,prs_arg);
					
					// var is defined and populated &  RHS is scalar -then stretch var to match
					if(Nvar && Nvar->flg_stt==2) 
					if(var1->sz ==1 && Nvar->var->sz >1){
					var1=nco_var_cnf_typ(Nvar->var->type,var1);  
					(void)ncap_att_stretch(var1,Nvar->var->sz);
					
					// this is a special case -- if the RHS scalar has
					// no missing value then retain LHS missing value
					// else LHS missing value gets over written by RHS
					if(!var1->has_mss_val)
					(void)nco_mss_val_cp(Nvar->var,var1);   
					}
					
					// Write var to disk
					(void)prs_arg->ncap_var_write(var1,bram);
					//(void)ncap_var_write_omp(var1,bram,prs_arg);
					
					// See If we have to return something
					if(vid2->getFirstChild() && vid2->getFirstChild()->getType()==NORET)
					var=NULL_CEWI;
					else 
					var=prs_arg->ncap_var_init(var_nm,true);               ;
					
					
#line 3040 "ncoTree.cpp"
				}
			}
			else {
				bool synPredMatched269 = false;
				if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
					_t = ASTNULL;
				if (((_t->getType() == ATT_ID))) {
					ANTLR_USE_NAMESPACE(antlr)RefAST __t269 = _t;
					synPredMatched269 = true;
					inputState->guessing++;
					try {
						{
						ANTLR_USE_NAMESPACE(antlr)RefAST __t268 = _t;
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp201_AST_in = _t;
						match(_t,ATT_ID);
						_t = _t->getFirstChild();
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp202_AST_in = _t;
						match(_t,LMT_LIST);
						_t = _t->getNextSibling();
						_t = __t268;
						_t = _t->getNextSibling();
						}
					}
					catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
						synPredMatched269 = false;
					}
					_t = __t269;
					inputState->guessing--;
				}
				if ( synPredMatched269 ) {
					ANTLR_USE_NAMESPACE(antlr)RefAST __t270 = _t;
					att = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
					match(_t,ATT_ID);
					_t = _t->getFirstChild();
					ANTLR_USE_NAMESPACE(antlr)RefAST tmp203_AST_in = _t;
					match(_t,LMT_LIST);
					_t = _t->getNextSibling();
					_t = __t270;
					_t = _t->getNextSibling();
					if ( inputState->guessing==0 ) {
#line 1943 "ncoGrammer.g"
						
						;
						
#line 3085 "ncoTree.cpp"
					}
				}
				else {
					bool synPredMatched273 = false;
					if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
						_t = ASTNULL;
					if (((_t->getType() == ATT_ID))) {
						ANTLR_USE_NAMESPACE(antlr)RefAST __t273 = _t;
						synPredMatched273 = true;
						inputState->guessing++;
						try {
							{
							ANTLR_USE_NAMESPACE(antlr)RefAST __t272 = _t;
							ANTLR_USE_NAMESPACE(antlr)RefAST tmp204_AST_in = _t;
							match(_t,ATT_ID);
							_t = _t->getFirstChild();
							ANTLR_USE_NAMESPACE(antlr)RefAST tmp205_AST_in = _t;
							match(_t,LMT_DMN);
							_t = _t->getNextSibling();
							_t = __t272;
							_t = _t->getNextSibling();
							}
						}
						catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
							synPredMatched273 = false;
						}
						_t = __t273;
						inputState->guessing--;
					}
					if ( synPredMatched273 ) {
						ANTLR_USE_NAMESPACE(antlr)RefAST __t274 = _t;
						att1 = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
						match(_t,ATT_ID);
						_t = _t->getFirstChild();
						ANTLR_USE_NAMESPACE(antlr)RefAST tmp206_AST_in = _t;
						match(_t,DMN_LIST);
						_t = _t->getNextSibling();
						_t = __t274;
						_t = _t->getNextSibling();
						if ( inputState->guessing==0 ) {
#line 1946 "ncoGrammer.g"
							
							;
							
#line 3130 "ncoTree.cpp"
						}
					}
					else if ((_t->getType() == ATT_ID)) {
						att2 = _t;
						match(_t,ATT_ID);
						_t = _t->getNextSibling();
						if ( inputState->guessing==0 ) {
#line 1949 "ncoGrammer.g"
							
							
							var_sct *var1;
							string sa=att2->getText();
							
							if(nco_dbg_lvl_get() >= nco_dbg_var) dbg_prn(fnc_nm,sa);
							
							var1=out(att2->getNextSibling());
							// we dont need missing values in ATT right !!
							if(var1->has_mss_val){
							var1->has_mss_val=False;
								          var1->mss_val.vp=(void*)nco_free(var1->mss_val.vp);
							}   
							
							// if RHS is a non scalar variable then loose superfluous dimension data 
							if( var1->nbr_dim >0){
							var_sct *var_tmp;
							var_tmp=ncap_sclr_var_mk(sa,var1->type,false);   
							var_tmp->sz=var1->sz;
							var_tmp->val.vp=var1->val.vp;     
							var1->val.vp =(void*)NULL;
							var1=nco_var_free(var1);
							var1=var_tmp;
							}else{   
							(void)nco_free(var1->nm);
							var1->nm=strdup(sa.c_str());
							}
							
							NcapVar *Nvar=new NcapVar(var1,sa);
							prs_arg->var_vtr.push_ow(Nvar);       
							
							// See If we have to return something
							if(att2->getFirstChild() && att2->getFirstChild()->getType()==NORET)
							var=NULL_CEWI;
							else 
							var=nco_var_dpl(var1);               ;
							
							
#line 3177 "ncoTree.cpp"
						}
					}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(_t);
		}
		}}}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return var;
}

var_sct * ncoTree::out_asn(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
#line 2373 "ncoGrammer.g"
	var_sct *var;
#line 3201 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST out_asn_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid1 = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST att = ANTLR_USE_NAMESPACE(antlr)nullAST;
#line 2373 "ncoGrammer.g"
	
	const std::string fnc_nm("assign_asn");
	var=NULL_CEWI; 
	string var_nm_s; 
	NcapVar *Nvar;
	
	
#line 3214 "ncoTree.cpp"
	
	try {      // for error handling
		if (_t == ANTLR_USE_NAMESPACE(antlr)nullAST )
			_t = ASTNULL;
		switch ( _t->getType()) {
		case UTIMES:
		{
			ANTLR_USE_NAMESPACE(antlr)RefAST __t343 = _t;
			ANTLR_USE_NAMESPACE(antlr)RefAST tmp207_AST_in = _t;
			match(_t,UTIMES);
			_t = _t->getFirstChild();
			vid1 = _t;
			match(_t,VAR_ID);
			_t = _t->getNextSibling();
			_t = __t343;
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2383 "ncoGrammer.g"
				
				if(vid1->getFirstChild())
				err_prn(fnc_nm,"Invalid Lvalue " +vid1->getText() );
				
				//do attribute inheritance 
				var_nm_s=vid1->getText(); 
				
				Nvar=prs_arg->var_vtr.find(var_nm_s);
				if( !Nvar || Nvar->flg_stt==1 ) 
				ncap_att_cpy(var_nm_s,var_nm_s,prs_arg);
				
				var=prs_arg->ncap_var_init(var_nm_s,true);
				if(var== NULL_CEWI){
				nco_exit(EXIT_FAILURE);
				}
				
				
#line 3250 "ncoTree.cpp"
			}
			break;
		}
		case VAR_ID:
		{
			vid = _t;
			match(_t,VAR_ID);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2401 "ncoGrammer.g"
				
				var_nm_s=vid->getText();  
				if(vid->getFirstChild())
				err_prn(fnc_nm,"Invalid Lvalue " +vid->getText() );
				
				//do attribute inheritance
				
				Nvar=prs_arg->var_vtr.find(var_nm_s);
				if( !Nvar || Nvar->flg_stt==1 ) 
				ncap_att_cpy(var_nm_s,var_nm_s,prs_arg);
				
				var=prs_arg->ncap_var_init(var_nm_s,true);
				
				
				
				if(var== NULL_CEWI){
				nco_exit(EXIT_FAILURE);
				}
				
				
#line 3281 "ncoTree.cpp"
			}
			break;
		}
		case ATT_ID:
		{
			att = _t;
			match(_t,ATT_ID);
			_t = _t->getNextSibling();
			if ( inputState->guessing==0 ) {
#line 2422 "ncoGrammer.g"
				
				// check "output"
				NcapVar *Nvar=NULL;
				
				if(att->getFirstChild())
				err_prn(fnc_nm,"Invalid Lvalue " +att->getText() );
				
				
				if(prs_arg->ntl_scn)
				Nvar=prs_arg->int_vtr.find(att->getText());
				
				if(Nvar==NULL) 
				Nvar=prs_arg->var_vtr.find(att->getText());
				
				var=NULL_CEWI;    
				if(Nvar !=NULL)
				var=nco_var_dpl(Nvar->var);
				else    
				var=ncap_att_init(att->getText(),prs_arg);
				
				if(!prs_arg->ntl_scn && var==NULL_CEWI ){
				err_prn(fnc_nm,"Unable to locate attribute " +att->getText()+ " in input or output files.");
				}
				
				// if att not found return undefined
				if(prs_arg->ntl_scn && var==NULL_CEWI )
				var=ncap_var_udf(att->getText().c_str());
				
				if(prs_arg->ntl_scn && var->val.vp !=NULL)
				var->val.vp=(void*)nco_free(var->val.vp);
				
				
#line 3324 "ncoTree.cpp"
			}
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(_t);
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return var;
}

var_sct * ncoTree::value_list(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
#line 2456 "ncoGrammer.g"
	var_sct *var;
#line 3350 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST value_list_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST vlst = ANTLR_USE_NAMESPACE(antlr)nullAST;
#line 2456 "ncoGrammer.g"
	
	const std::string fnc_nm("value_list");
	var=NULL_CEWI; 
	
#line 3358 "ncoTree.cpp"
	
	try {      // for error handling
		{
		vlst = _t;
		match(_t,VALUE_LIST);
		_t = _t->getNextSibling();
		}
		if ( inputState->guessing==0 ) {
#line 2461 "ncoGrammer.g"
			
			
			char *cp;
			int nbr_lst;
			int idx;
			int tsz;
			
			nc_type type=NC_NAT;
			var_sct *var_ret;                        
			RefAST rRef;
			std::vector<var_sct*> exp_vtr;
			
			rRef=vlst->getFirstChild();
			
			while(rRef){
			exp_vtr.push_back(out(rRef));   
			rRef=rRef->getNextSibling();
			}       
			nbr_lst=exp_vtr.size();
			
			// if any types are NC_STRING then call value_list_string() action 
			for(idx=0;idx <nbr_lst ;idx++)
			if(exp_vtr[idx]->type == NC_STRING){
			var_ret=value_list_string(rRef,exp_vtr);
			goto end_val;
			}
			
			// find highest type
			for(idx=0;idx <nbr_lst ;idx++)
			type=ncap_typ_hgh(type,exp_vtr[idx]->type);
			//(void)ncap_var_retype(exp_vtr[0], exp_vtr[idx]);  
			
			// Inital Scan
			if(prs_arg->ntl_scn){
			
			for(idx=0 ; idx <nbr_lst ; idx++) 
			if(exp_vtr[idx]->undefined) break;
			
			// Exit if an element in the list is "undefined" 
			if(idx < nbr_lst){ 
			var_ret=ncap_var_udf("~zz@value_list");  
			goto end_val;  
			}
			
			var_ret=(var_sct *)nco_malloc(sizeof(var_sct));
			/* Set defaults */
			(void)var_dfl_set(var_ret); 
			
			/* Overwrite with attribute expression information */
			var_ret->nm=strdup("~zz@value_list");
			var_ret->nbr_dim=0;
			var_ret->sz=nbr_lst;
			var_ret->type=type;
			
			goto end_val;          
			
			} // end initial scan
			
			// convert every element in vector to highest type
			for(idx=0;idx <nbr_lst ;idx++)
			exp_vtr[idx]=nco_var_cnf_typ(type,exp_vtr[idx]);  
			
			var_ret=(var_sct *)nco_malloc(sizeof(var_sct));
			/* Set defaults */
			(void)var_dfl_set(var_ret); 
			
			/* Overwrite with attribute expression information */
			var_ret->nm=strdup("~zz@value_list");
			var_ret->nbr_dim=0;
			var_ret->sz=nbr_lst;
			var_ret->type=type;
			
			tsz=nco_typ_lng(type);
			var_ret->val.vp=(void*)nco_malloc(nbr_lst*tsz);
			
			for(idx=0;idx <nbr_lst ; idx++){
			cp=(char*)(var_ret->val.vp)+ (ptrdiff_t)(idx*tsz);
			memcpy(cp,exp_vtr[idx]->val.vp,tsz);
			}    
			
			// Free vector        
			end_val: for(idx=0 ; idx < nbr_lst ; idx++)
			(void)nco_var_free(exp_vtr[idx]);    
			
			var=var_ret;
			
			
#line 3455 "ncoTree.cpp"
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return var;
}

var_sct * ncoTree::value_list_string(ANTLR_USE_NAMESPACE(antlr)RefAST _t,
	 std::vector<var_sct*> &exp_vtr
) {
#line 2552 "ncoGrammer.g"
	var_sct *var;
#line 3476 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST value_list_string_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
#line 2552 "ncoGrammer.g"
	
	const std::string fnc_nm("value_list_string");
	var=NULL_CEWI; 
	
#line 3483 "ncoTree.cpp"
	
	try {      // for error handling
		if ( inputState->guessing==0 ) {
#line 2558 "ncoGrammer.g"
			
			int idx;
			int nbr_lst;
			int tsz;
			nco_string *cp;         
			var_sct *var_ret;                        
			
			nbr_lst=exp_vtr.size();
			var_ret=(var_sct *)nco_malloc(sizeof(var_sct));
			/* Set defaults */
			(void)var_dfl_set(var_ret); 
			
			/* Overwrite with attribute expression information */
			var_ret->nm=strdup("~zz@value_list");
			var_ret->nbr_dim=0;
			var_ret->sz=nbr_lst;
			var_ret->type=(nc_type)NC_STRING;
			
			// Inital Scan
			if(prs_arg->ntl_scn)
			goto end_val;          
			
			// check all var types in vector must be type NC_STRING
			for(idx=0; idx<nbr_lst ; idx++)
			if( exp_vtr[idx]->type != NC_STRING)
			err_prn(fnc_nm," error processing value list string: to successfully parse value list of strings all elements must be of type NC_STRING");
			
			// from here on deal with final scan
			tsz=nco_typ_lng((nc_type)NC_STRING);
			var_ret->val.vp=(void*)nco_malloc(nbr_lst*tsz);
			
			(void)cast_void_nctype((nc_type)NC_STRING,&var_ret->val);
			cp=var_ret->val.sngp; 
			
			for(idx=0 ; idx<nbr_lst;idx++){
			// dereference 
			var_sct *var_in=exp_vtr[idx];
			(void)cast_void_nctype((nc_type)NC_STRING,&var_in->val);
			cp[idx]=strdup(var_in->val.sngp[0]); 
			// cast pointer back
			(void)cast_nctype_void((nc_type)NC_STRING,&var_in->val);
			} // end loop      
			
			(void)cast_nctype_void((nc_type)NC_STRING,&var_ret->val);
			
			end_val: var=var_ret;
			
			
#line 3536 "ncoTree.cpp"
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return var;
}

bool  ncoTree::where_assign(ANTLR_USE_NAMESPACE(antlr)RefAST _t,
	var_sct *var_msk
) {
#line 2609 "ncoGrammer.g"
	bool bret=false;
#line 3557 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST where_assign_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid = ANTLR_USE_NAMESPACE(antlr)nullAST;
#line 2609 "ncoGrammer.g"
	
	const std::string fnc_nm("where_assign");
	var_sct *var_rhs;
	
	
#line 3566 "ncoTree.cpp"
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t348 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp208_AST_in = _t;
		match(_t,EXPR);
		_t = _t->getFirstChild();
		ANTLR_USE_NAMESPACE(antlr)RefAST __t349 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp209_AST_in = _t;
		match(_t,ASSIGN);
		_t = _t->getFirstChild();
		vid = _t;
		match(_t,VAR_ID);
		_t = _t->getNextSibling();
		var_rhs=out(_t);
		_t = _retTree;
		_t = __t349;
		_t = _t->getNextSibling();
		_t = __t348;
		_t = _t->getNextSibling();
		if ( inputState->guessing==0 ) {
#line 2615 "ncoGrammer.g"
			
			
			bool bfr=false;
			nco_bool DO_CONFORM;
			std::string var_nm=vid->getText();
			var_sct *var_lhs;
			NcapVar *Nvar;
			
			bret=false;
			
			var_lhs=prs_arg->ncap_var_init(var_nm,true);
			if(var_lhs==NULL_CEWI) 
			nco_exit(EXIT_FAILURE);
			
			var_rhs=nco_var_cnf_typ(var_lhs->type,var_rhs);         
			if(var_rhs->sz >1L && var_rhs->sz != var_lhs->sz) {
			var_sct *var_tmp=NULL_CEWI;
			//  try and make RHS conform to LHS
			var_tmp=nco_var_cnf_dmn(var_lhs,var_rhs,var_tmp,True,&DO_CONFORM);
			
			if(DO_CONFORM==False) {
			std::ostringstream os;
			os<<"Cannot make variable:"<<var_lhs->nm <<" and  variable "<<var_rhs->nm <<" conform in where statement.";
			err_prn(fnc_nm,os.str()); 
			}
			
			if(var_rhs != var_tmp){
			var_rhs=nco_var_free(var_rhs);
			var_rhs=var_tmp;
			}  
			}
			
			// Make mask conform
			if(var_msk->sz != var_lhs->sz){
			var_sct *var_tmp=NULL_CEWI;
			var_tmp=nco_var_cnf_dmn(var_lhs,var_msk,var_tmp,True,&DO_CONFORM);
			
			if(DO_CONFORM==False) {
			std::ostringstream os;
			os<<"Cannot make variable:"<<var_lhs->nm <<" and where mask variable "<<var_msk->nm <<" conform. ";
			err_prn(fnc_nm,os.str()); 
			}
			
			if(var_msk != var_tmp){
			//var_msk=nco_var_free(var_msk);
			bfr=true;
			var_msk=var_tmp;
			}
			}
			
			char *cp_in;
			char *cp_out;
			short *sp;
			long idx;
			long jdx;
			long sz;
			size_t slb_sz;
			bool b_vp=false;
			char *mss_cp;
			
			sz=var_lhs->sz;
			slb_sz=nco_typ_lng(var_lhs->type);
			
			(void)cast_void_nctype(NC_SHORT,&var_msk->val);
			//Dereference 
			sp=var_msk->val.sp; 
			
			cp_out=( char*)(var_lhs->val.vp);
			cp_in=( char*)(var_rhs->val.vp);
			
			if(var_lhs->has_mss_val) {
			mss_cp=( char*)var_lhs->mss_val.vp;
			b_vp=true;
			} else if(var_rhs->has_mss_val){
			mss_cp=( char*)var_rhs->mss_val.vp;
			b_vp=true;                 
			}        
			// missing values    
			if(b_vp) {
			if(var_rhs->sz==1L){ 
			
			for(idx=0; idx<sz; idx++) {
			if(sp[idx] && memcmp(cp_out,mss_cp,slb_sz))
			(void)memcpy(cp_out,cp_in,slb_sz);       
			cp_out+=slb_sz;
			} 
			} else {  
			for(idx=0; idx<sz; idx++) {
			if(sp[idx]&& memcmp(cp_out,mss_cp,slb_sz) 
			&& memcmp(cp_in,mss_cp,slb_sz))
			(void)memcpy(cp_out,cp_in,slb_sz);      
			cp_out+=slb_sz;
			cp_in+=slb_sz;
			}
			} 
			// no missing values                
			} else { 
			
			if(var_rhs->sz==1L){ 
			
			for(idx=0; idx<sz; idx++) {
			if(sp[ idx])
			(void)memcpy(cp_out,cp_in,slb_sz);       
			cp_out+=slb_sz;
			} 
			} else {  
			for(idx=0; idx<sz; idx++) {
			if(sp[idx])
			(void)memcpy(cp_out,cp_in,slb_sz);      
			cp_out+=slb_sz;
			cp_in+=slb_sz;
			}
			} 
			}             
			
			(void)cast_nctype_void(NC_SHORT,&var_msk->val); 
			
			// free "local" copy of var_msk if necessary
			if(bfr)
			var_msk=nco_var_free(var_msk);           
			
			// Do attribute propagation if LHS is new
			Nvar=prs_arg->var_vtr.find(var_nm);
			if(!Nvar)
			(void)ncap_att_cpy(var_nm,std::string(var_rhs->nm),prs_arg);
			
			var_rhs=nco_var_free(var_rhs);
			
			prs_arg->ncap_var_write(var_lhs,false);
			bret=true;
			
#line 3719 "ncoTree.cpp"
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return bret;
}

var_sct * ncoTree::var_lmt_one(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
#line 2750 "ncoGrammer.g"
	var_sct *var;
#line 3738 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST var_lmt_one_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid = ANTLR_USE_NAMESPACE(antlr)nullAST;
#line 2750 "ncoGrammer.g"
	
	const std::string fnc_nm("var_lmt_one");
	var=NULL_CEWI; 
	var_sct *var_nbr;
	
#line 3747 "ncoTree.cpp"
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t351 = _t;
		vid = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
		match(_t,VAR_ID);
		_t = _t->getFirstChild();
		ANTLR_USE_NAMESPACE(antlr)RefAST __t352 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp210_AST_in = _t;
		match(_t,LMT_LIST);
		_t = _t->getFirstChild();
		ANTLR_USE_NAMESPACE(antlr)RefAST __t353 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp211_AST_in = _t;
		match(_t,LMT);
		_t = _t->getFirstChild();
		var_nbr=out(_t);
		_t = _retTree;
		_t = __t353;
		_t = _t->getNextSibling();
		_t = __t352;
		_t = _t->getNextSibling();
		_t = __t351;
		_t = _t->getNextSibling();
		if ( inputState->guessing==0 ) {
#line 2756 "ncoGrammer.g"
			
			
			int idx;
			var_sct *var_rhs;
			std::string var_nm;
			
			var_nm=vid->getText(); 
			var_rhs=prs_arg->ncap_var_init(var_nm,false);            
			
			if(var_rhs->undefined){
			var=ncap_var_udf("~rhs_undefined");       
			goto end0;  // cannot use return var!!
			}
			
			if(prs_arg->ntl_scn){
			var=ncap_sclr_var_mk(var_nm,(nc_type)(var_rhs->type),false);
			}else{
			bool bram;
			int fl_id;
			int nbr_dim=var_rhs->nbr_dim;
			long srt; 
			long srt1[NC_MAX_DIMS];   
			long sz_dim=1;
			NcapVar *Nvar;
			
			// create var with space for value
			var=ncap_sclr_var_mk(var_nm,(nc_type)(var_rhs->type),true);
			
			// we have already checked limit is a single value
			// in the calling action earlier  in the tree parser
			//var_nbr=out(lmt->getFirstChild());
			
			var_nbr=nco_var_cnf_typ(NC_INT,var_nbr); 
			(void)cast_void_nctype(NC_INT,&var_nbr->val);
			srt=var_nbr->val.ip[0];
			(void)cast_nctype_void(NC_INT,&var_nbr->val);
			
			// fortran index convention   
			if(prs_arg->FORTRAN_IDX_CNV)
			srt--;
			else if ( srt<0) 
			srt+=var_rhs->sz-1; // deal with negative index 
			
			// do some bounds checking
			if(srt >= var_rhs->sz || srt<0 )
			err_prn(fnc_nm,"Limit of "+ nbr2sng(srt) +" for variable \""+ var_nm+"\" with size="+nbr2sng(var_rhs->sz)+" is out of bounds\n"); 
			
			// check for RAM variable  
			Nvar=prs_arg->var_vtr.find(var_nm);
			if(Nvar && Nvar->flg_mem)
			bram=true;
			else
			bram=false;
			
			if(bram){
			// deal with RAM variable
			size_t slb_sz;
			slb_sz=nco_typ_lng(var_rhs->type);     
			
			(void)memcpy(var->val.vp,(const char*)Nvar->var->val.vp+(ptrdiff_t)(srt*slb_sz),slb_sz);
			}else{ 
			
			// variable in output and defined
			if(Nvar && Nvar->flg_stt==2) {
			#ifdef _OPENMP
			fl_id=( omp_in_parallel() ? prs_arg->out_id_readonly : prs_arg->out_id );
			#else    
			fl_id=prs_arg->out_id;  
			#endif      
			// variable output but undefined        
			}else if(Nvar && Nvar->flg_stt==1) {
			fl_id=prs_arg->in_id;
			(void)nco_inq_varid(fl_id,var_nm.c_str(),&var_rhs->id);
			
			// variable in input
			}else{
			fl_id=prs_arg->in_id; 
			}
			
			// convert srt into multiple indices  
			for(idx=0;idx<nbr_dim;idx++)
			sz_dim*= var_rhs->cnt[idx]; 
			
			for(idx=0; idx<nbr_dim; idx++){                   
			sz_dim/=var_rhs->cnt[idx];
			srt1[idx]=srt/sz_dim; 
			srt-=srt1[idx]*sz_dim;
			}
			(void)nco_get_var1(fl_id,var_rhs->id,srt1,var->val.vp,var_rhs->type);  
			
			} // end else !bram
			
			// copy missing value if any over             
			nco_mss_val_cp(var_rhs,var);
			
			} // end else !prs_arg->ntl_scn 
			
			end0:       var_nbr=nco_var_free(var_nbr);
			var_rhs=nco_var_free(var_rhs);   
			
#line 3872 "ncoTree.cpp"
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return var;
}

var_sct * ncoTree::var_lmt_one_lhs(ANTLR_USE_NAMESPACE(antlr)RefAST _t,
	bool bram
) {
#line 2861 "ncoGrammer.g"
	var_sct *var;
#line 3893 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST var_lmt_one_lhs_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid = ANTLR_USE_NAMESPACE(antlr)nullAST;
#line 2861 "ncoGrammer.g"
	
	const std::string fnc_nm("var_lmt_one_lhs");
	var=NULL_CEWI; 
	var_sct *var_nbr;
	
#line 3902 "ncoTree.cpp"
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t355 = _t;
		vid = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
		match(_t,VAR_ID);
		_t = _t->getFirstChild();
		ANTLR_USE_NAMESPACE(antlr)RefAST __t356 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp212_AST_in = _t;
		match(_t,LMT_LIST);
		_t = _t->getFirstChild();
		ANTLR_USE_NAMESPACE(antlr)RefAST __t357 = _t;
		ANTLR_USE_NAMESPACE(antlr)RefAST tmp213_AST_in = _t;
		match(_t,LMT);
		_t = _t->getFirstChild();
		var_nbr=out(_t);
		_t = _retTree;
		_t = __t357;
		_t = _t->getNextSibling();
		_t = __t356;
		_t = _t->getNextSibling();
		_t = __t355;
		_t = _t->getNextSibling();
		if ( inputState->guessing==0 ) {
#line 2867 "ncoGrammer.g"
			
			int idx; 
			int var_id; 
			int slb_sz;
			long srt;
			
			std::string var_nm;
			
			var_sct *var_lhs=NULL_CEWI;
			var_sct *var_rhs=NULL_CEWI;
			NcapVar *Nvar; 
			
			var_nm=vid->getText(); 
			
			if(nco_dbg_lvl_get() > nco_dbg_var) dbg_prn(fnc_nm,var_nm+"(limit)");
			
			Nvar=prs_arg->var_vtr.find(var_nm);
			
			// calculate single hyperslab limit
			var_nbr=nco_var_cnf_typ(NC_INT,var_nbr); 
			(void)cast_void_nctype(NC_INT,&var_nbr->val);
			srt=var_nbr->val.ip[0];
			(void)cast_nctype_void(NC_INT,&var_nbr->val);
			
			// Overwrite bram possibly 
			if(Nvar) 
			bram=Nvar->flg_mem;
			
			// Deal with RAM variables
			if(bram){
			
			if(Nvar){
			//defined but not-populated 
			if(Nvar->flg_stt==1){ 
			var_sct *var_ini;
			var_ini=prs_arg->ncap_var_init(var_nm,true);       
			Nvar->var->val.vp=var_ini->val.vp;
			var_ini->val.vp=(void*)NULL;
			var_ini=nco_var_free(var_ini);
			Nvar->flg_stt=2; 
			} 
			//defined and populated 
			if(Nvar->flg_stt==2)
			var_lhs=Nvar->var;                        
			
			}else{
			var_lhs=prs_arg->ncap_var_init(var_nm,true);       
			}
			
			// fortran index convention   
			if(prs_arg->FORTRAN_IDX_CNV)
			srt--;
			else if(srt<0) srt+=var_lhs->sz-1; //deal with negative index convention 
			
			// do some bounds checking on single limits
			if(srt >= var_lhs->sz || srt<0 )
			err_prn(fnc_nm,"Limit of "+ nbr2sng(srt) +" for variable \""+ var_nm+"\" with size="+nbr2sng(var_lhs->sz)+" is out of bounds\n"); 
			
			//calculate rhs
			var_rhs=out(vid->getNextSibling());   
			
			// we are only hyperslabbing a single value 
			if(var_rhs->sz !=1)
			err_prn(fnc_nm, "Hyperslab for "+var_nm+" - number of elements on LHS(1) doesn't equal number of elements on RHS(" +nbr2sng(var_rhs->sz) +  ")");                                       
			
			
			// Convert to LHS type
			var_rhs=nco_var_cnf_typ(var_lhs->type,var_rhs);             
			
			slb_sz=nco_typ_lng(var_lhs->type);     
			(void)memcpy((char*)var_lhs->val.vp+(ptrdiff_t)(srt*slb_sz),var_rhs->val.vp,slb_sz);    
			
			if(!Nvar)
			(void)prs_arg->ncap_var_write(var_lhs,true); 
			
			// deal with regular vars 
			}else{
			
			// if var undefined in O or defined but not populated
			if(!Nvar || ( Nvar && Nvar->flg_stt==1)){              
			// if var isn't in ouptut then copy it there
			var_lhs=prs_arg->ncap_var_init(var_nm,true);
			
			// copy atts to output
			(void)ncap_att_cpy(var_nm,var_nm,prs_arg);
			(void)prs_arg->ncap_var_write(var_lhs,false);
			}
			
			var_lhs=prs_arg->ncap_var_init(var_nm,false);
			
			// fortran index convention   
			if(prs_arg->FORTRAN_IDX_CNV)
			srt--;
			else if(srt<0) srt+=var_lhs->sz-1; //deal with negative index convention 
			
			// do some bounds checking on single limits
			if(srt >= var_lhs->sz || srt<0 )
			err_prn(fnc_nm,"Limit of "+ nbr2sng(srt) +" for variable \""+ var_nm+"\" with size="+nbr2sng(var_lhs->sz)+" is out of bounds\n"); 
			
			// Grab RHS
			var_rhs=out(vid->getNextSibling());   
			
			// we are only hyperslabbing a single value 
			if(var_rhs->sz !=1)
			err_prn(fnc_nm, "Hyperslab for "+var_nm+" - number of elements on LHS(1) doesn't equal number of elements on RHS(" +nbr2sng(var_rhs->sz) +  ")");                                       
			
			// Convert to LHS type
			var_rhs=nco_var_cnf_typ(var_lhs->type,var_rhs);             
			
			// swap values about
			var_lhs->val.vp=var_rhs->val.vp; 
			var_rhs->val.vp=(void*)NULL; 
			
			// write block
			{ 
			int nbr_dim=var_lhs->nbr_dim;
			long srt1[NC_MAX_DIMS];   
			long sz_dim=1; 
			
			// convert srt into multiple indices  
			for(idx=0;idx<nbr_dim;idx++)
			sz_dim*= var_lhs->cnt[idx]; 
			
			for(idx=0; idx<nbr_dim; idx++){                   
			sz_dim/=var_lhs->cnt[idx];
			srt1[idx]=srt/sz_dim; 
			srt-=srt1[idx]*sz_dim;
			}
			
			for(idx=0;idx<nbr_dim;idx++){
			var_lhs->srt[idx]=srt1[idx]; 
			var_lhs->cnt[idx]=1L; 
			var_lhs->srd[idx]=1L; 
			} /* end loop over idx */
			
			// write slab to O contains call to Open MP critical region
			//  routine also frees up var_lhs
			(void)prs_arg->ncap_var_write_slb(var_lhs);     
			
			}//end write block 
			}     
			var_rhs=nco_var_free(var_rhs); 
			var_nbr=nco_var_free(var_nbr); 
			
#line 4071 "ncoTree.cpp"
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return var;
}

var_sct * ncoTree::var_lmt(ANTLR_USE_NAMESPACE(antlr)RefAST _t) {
#line 3015 "ncoGrammer.g"
	var_sct *var;
#line 4090 "ncoTree.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefAST var_lmt_AST_in = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
	ANTLR_USE_NAMESPACE(antlr)RefAST vid = ANTLR_USE_NAMESPACE(antlr)nullAST;
	ANTLR_USE_NAMESPACE(antlr)RefAST lmt = ANTLR_USE_NAMESPACE(antlr)nullAST;
#line 3015 "ncoGrammer.g"
	
	const std::string fnc_nm("var_lmt");
	var=NULL_CEWI; 
	
#line 4099 "ncoTree.cpp"
	
	try {      // for error handling
		ANTLR_USE_NAMESPACE(antlr)RefAST __t359 = _t;
		vid = (_t == ANTLR_USE_NAMESPACE(antlr)RefAST(ASTNULL)) ? ANTLR_USE_NAMESPACE(antlr)nullAST : _t;
		match(_t,VAR_ID);
		_t = _t->getFirstChild();
		lmt = _t;
		match(_t,LMT_LIST);
		_t = _t->getNextSibling();
		_t = __t359;
		_t = _t->getNextSibling();
		if ( inputState->guessing==0 ) {
#line 3020 "ncoGrammer.g"
			
			bool bram;   // Check for a RAM variable
			bool bnrm;
			int idx;
			int nbr_dmn;
			int fl_id;
			
			var_sct *var1;
			var_sct *var_rhs;
			
			std::string var_nm;
			
			NcapVar *Nvar;
			RefAST lRef;           
			
			NcapVector<lmt_sct*> lmt_vtr;
			NcapVector<dmn_sct*> dmn_vtr;
			NcapVector<std::string> dmn_nrm_vtr;  // list of dimension names
			
			var_nm=vid->getText(); 
			var_rhs=prs_arg->ncap_var_init(var_nm,false);            
			
			if(var_rhs->undefined){
			var=ncap_var_udf("~rhs_undefined");       
			goto end2;  // cannot use return var!!
			}
			
			nbr_dmn=var_rhs->nbr_dim;          
			lRef=lmt;
			
			if(prs_arg->ntl_scn){
			// check limit only contains numbers or dim_id.size()
			std::vector<std::string> str_vtr;
			(void)ncap_mpi_get_id(lRef,str_vtr);
			if(str_vtr.size()>0){
			var=ncap_var_udf("~rhs_undefined");       
			goto end2;  // cannot use return var!!
			}
			// Temporarily change mode 
			prs_arg->ntl_scn=False;
			lmt_mk(nbr_dmn,lRef,lmt_vtr);
			prs_arg->ntl_scn=True; 
			
			}else{
			lmt_mk(nbr_dmn,lRef,lmt_vtr);
			}
			
			if( lmt_vtr.size() != nbr_dmn)
			err_prn(fnc_nm,"Number of hyperslab limits for variable "+ var_nm+" doesn't match number of dimensions");
			
			// add dim names to dimension list 
			for(idx=0 ; idx < nbr_dmn;idx++)
			lmt_vtr[idx]->nm=strdup(var_rhs->dim[idx]->nm);   
			
			// fill out limit structure
			for(idx=0 ; idx < nbr_dmn ;idx++)
			(void)ncap_lmt_evl(var_rhs->nc_id,lmt_vtr[idx],prs_arg);
			
			// See if var can be normalized
			for(idx=0; idx<nbr_dmn ; idx++){
			if(lmt_vtr[idx]->cnt==1) continue;
			
			if(lmt_vtr[idx]->cnt == var_rhs->dim[idx]->cnt) 
			dmn_nrm_vtr.push_back(std::string(lmt_vtr[idx]->nm));
			else
			break;
			} 
			
			bnrm= (idx==nbr_dmn ? true:false);       
			
			// deal more with inital scan 
			if(prs_arg->ntl_scn){
			
			if(bnrm){   
			
			var=ncap_cst_mk(dmn_nrm_vtr,prs_arg);
			
			(void)nco_free(var->nm);
			var->nm=strdup(var_nm.c_str());
			
			var=nco_var_cnf_typ(var_rhs->type,var);
			
			// apply LHS cast if necessary 
			if(var->sz>1 && bcst) 
			var=ncap_cst_do(var,var_cst,prs_arg->ntl_scn);
			}else{
			var=ncap_var_udf("~rhs_undefined");             
			}
			goto end1;
			}           
			
			/**** From here on we are dealing with a final scan  ****/
			// copy lmt_sct to dmn_sct;
			for(idx=0 ;idx <nbr_dmn ; idx++){
			dmn_sct *dmn_nw;
			dmn_nw=(dmn_sct*)nco_malloc(sizeof(dmn_sct));
			dmn_nw->nm=strdup(lmt_vtr[idx]->nm);
			
			// Fudge -if the variable is from input then nco_lmt_evl
			// overwrites the dim id's with their input file values
			// we want the dim ids from output  
			dmn_nw->id=var_rhs->dim[idx]->id;
			//dmn_nw->id=lmt_vtr[idx]->id;
			dmn_nw->cnt=lmt_vtr[idx]->cnt;  
			dmn_nw->srt=lmt_vtr[idx]->srt;  
			dmn_nw->end=lmt_vtr[idx]->end;  
			dmn_nw->srd=lmt_vtr[idx]->srd;  
			dmn_vtr.push_back(dmn_nw);
			}
			
			Nvar=prs_arg->var_vtr.find(var_nm);
			if(Nvar && Nvar->flg_mem)
			bram=true;
			else
			bram=false;
			
			// Ram variable -do an in memory get  
			if(bram){
			var=prs_arg->ncap_var_init(var_nm,true);                         
			//Do an in memory get 
			(void)nco_get_var_mem(var,dmn_vtr);
			// put values from dmn_vtr back into var
			// nb above call has already calculated correct value for
			// var->sz;
			for(idx=0;idx<nbr_dmn ;idx++){
			var->srt[idx]=dmn_vtr[idx]->srt;
			var->end[idx]=dmn_vtr[idx]->end;
			var->cnt[idx]=dmn_vtr[idx]->cnt;
			var->srd[idx]=dmn_vtr[idx]->srd;
			}
			// regular variable
			}else{
			
			// variable in output 
			if(Nvar){
			#ifdef _OPENMP
			fl_id=( omp_in_parallel() ? prs_arg->out_id_readonly : prs_arg->out_id);
			#else    
			fl_id=prs_arg->out_id;  
			#endif      
			// variable in input         
			}else{ 
			fl_id=prs_arg->in_id;
			}
			
			// Fudge -- fill out var again -but using dims defined in dmn_vtr
			// We need data in var so that LHS logic in assign can access var shape 
			var=nco_var_fll(fl_id,var_rhs->id,var_nm.c_str(), &dmn_vtr[0],dmn_vtr.size()); 
			//var->sz*=2;
			// Now get data from disk - use nco_var_get() 
			(void)nco_var_get(fl_id,var); 
			
			} // end if(nbram)
			
			// copy missing value over
			nco_mss_val_cp(var_rhs,var);
			
			/* a hack - we set var->has_dpl_dmn=-1 so we know we are dealing with 
			a hyperslabbed var and not a regular var  -- It shouldn't cause 
			any abberant behaviour!! */ 
			var->has_dpl_dmn=-1;  
			
			// if variable is scalar re-organize in a new var 
			// loose extraneous material so it looks like a
			// plain scalar variable
			if(var->sz ==1) {
			
			var1=ncap_sclr_var_mk(var_nm,var->type,true);
			(void)memcpy( (void*)var1->val.vp,var->val.vp,nco_typ_lng(var1->type));
			
			// copy missing value if any from var_rhs to var1
			nco_mss_val_cp(var_rhs,var1);
			
			// free main var
			var=nco_var_free(var);
			
			var=var1;
			
			// if hyperslab -nomalizable 
			// nb the returned var is just like a regular var 
			}else if(bnrm) {
			
			// nb dmn_nrm_vtr was populated much earlier in function
			var1=ncap_cst_mk(dmn_nrm_vtr,prs_arg);
			(void)nco_free(var1->nm);
			
			var1->nm=strdup(var_nm.c_str());
			var1=nco_var_cnf_typ(var_rhs->type,var1);
			
			// copy missing value if any from var_rhs to var
			nco_mss_val_cp(var_rhs,var1);
			
			// swap values about in var1 & var 
			var1->val.vp=var->val.vp;
			
			var->val.vp=(void*)NULL;       
			
			// free var  
			(void)nco_var_free(var);    
			
			/* Casting a hyperslab --this makes my brain  hurt!!! 
			if the var is already the correct size then do nothing 
			what not even dimension reordering ?  */  
			if(bcst && var1->sz != var_cst->sz)
			var1=ncap_cst_do(var1,var_cst,prs_arg->ntl_scn);
			
			var=var1;
			
			}else{
			
			/* A sophisticated hack, var->dim currently contains 
			the local dims from dmn_vtr . We cannot leave them in 
			place as they will never be freed up, and if the var is 
			copied then complications will result. 
			So we replace them with the regular dims in
			prs_arg->dmn_out_vtr.
			
			Currently only one function explicitly references these dims
			This is the agg_cls::fnd -- The  Aggregate Functions
			
			Unpredicable behaviour will result when this hyperslabbed var 
			is passed to other functions
			
			*/                      
			for(idx=0 ; idx<nbr_dmn; idx++)
			var->dim[idx]=prs_arg->dmn_out_vtr.find(dmn_vtr[idx]->nm);  
			
			}   
			
			//free vectors
			for(idx=0 ; idx < nbr_dmn ; idx++)
			(void)nco_dmn_free(dmn_vtr[idx]); 
			;
			
			end1: ;
			for(idx=0 ; idx < nbr_dmn ; idx++)
			(void)nco_lmt_free(lmt_vtr[idx]);
			
			end2: var_rhs=nco_var_free(var_rhs); 
			
#line 4353 "ncoTree.cpp"
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		if( inputState->guessing == 0 ) {
			reportError(ex);
			if ( _t != ANTLR_USE_NAMESPACE(antlr)nullAST )
				_t = _t->getNextSibling();
		} else {
			throw;
		}
	}
	_retTree = _t;
	return var;
}

void ncoTree::initializeASTFactory( ANTLR_USE_NAMESPACE(antlr)ASTFactory& )
{
}
const char* ncoTree::tokenNames[] = {
	"<0>",
	"EOF",
	"<2>",
	"NULL_TREE_LOOKAHEAD",
	"NULL_NODE",
	"BLOCK",
	"ARG_LIST",
	"DMN_LIST",
	"DMN_ARG_LIST",
	"LMT_LIST",
	"VALUE_LIST",
	"FUNC_ARG",
	"LMT",
	"EXPR",
	"FEXPR",
	"POST_INC",
	"POST_DEC",
	"UTIMES",
	"PROP",
	"FOR2",
	"NORET",
	"ATAN2",
	"WHERE_ASSIGN",
	"MISS2ZERO",
	"VSORT",
	"VRSORT",
	"VABS",
	"VSQR2",
	"DEFDIM",
	";",
	"\"defdim\"",
	"\"defdimunlim\"",
	"(",
	"a string",
	",",
	")",
	"\"while\"",
	"\"break\"",
	"\"continue\"",
	"\"if\"",
	"\"else\"",
	"\"where\"",
	"\"elsewhere\"",
	"\"print\"",
	"VAR_ID",
	"ATT_ID",
	"{",
	"}",
	"\"for\"",
	":",
	"[",
	"DIM_ID",
	"]",
	"/",
	"dimension identifier",
	"call by reference",
	"dot operator",
	"FUNC",
	"++",
	"--",
	"!",
	"+",
	"-",
	"*",
	"power of operator",
	"%",
	"<<",
	">>",
	"<",
	">",
	">=",
	"<=",
	"==",
	"!=",
	"&&",
	"||",
	"?",
	"=",
	"+=",
	"-=",
	"*=",
	"/=",
	"NCAP_FLOAT",
	"NCAP_DOUBLE",
	"NCAP_INT",
	"NCAP_BYTE",
	"NCAP_UBYTE",
	"NCAP_SHORT",
	"NCAP_USHORT",
	"NCAP_UINT",
	"NCAP_INT64",
	"NCAP_UINT64",
	"N4STRING",
	"DIM_ID_SIZE",
	"NRootAST",
	"\"<<\"",
	"\">>\"",
	"\\\"",
	"DGT",
	"LPH",
	"LPHDGT",
	"XPN",
	"VAR_NM_QT",
	"BLASTOUT",
	"UNUSED_OPS",
	"white space",
	"a C++-style comment",
	"a C-style comment",
	"a floating point number",
	"NUMBER",
	"variable or function or attribute identifier",
	"VAR_ATT_QT",
	"DIM_QT",
	"dimension identifier",
	"INCLUDE",
	"LMT_DMN",
	0
};



